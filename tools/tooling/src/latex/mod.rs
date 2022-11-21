pub mod file_manager;

use std::borrow::Cow;
use std::fs;
use std::fs::{create_dir, remove_dir, remove_dir_all};
use std::path::{Path, PathBuf};
use anyhow::{anyhow, Context, Result};
use clap::builder::Str;
use pathdiff::diff_paths;
use tectonic::config::{BundleInfo, PersistentConfig};
use tectonic::driver::{OutputFormat, ProcessingSessionBuilder};
use tectonic::latex_to_pdf;
use tectonic::status::plain::PlainStatusBackend;
use tectonic::status::{ChatterLevel, NoopStatusBackend, StatusBackend};
use tectonic::status::termcolor::TermcolorStatusBackend;
use tectonic::unstable_opts::UnstableArg::PaperSize;
use tectonic::unstable_opts::UnstableOptions;
use tectonic_bridge_core::SecuritySettings;
use tectonic_bridge_core::SecurityStance::MaybeAllowInsecures;
use tectonic_bundles::{get_fallback_bundle, get_fallback_bundle_url};
use crate::latex::file_manager::{get_normalized_path, TempRepository};

pub struct CodeCompilation {
    pub name: String,
    pub project_path: PathBuf,
    pub model: PathBuf,
    pub contents: Vec<CompilationFile>,
}

pub struct CompilationFile {
    pub path: PathBuf,
    pub name: String,
}

pub fn get_included_files_contents(files: &Vec<CompilationFile>, project_path: &Path) -> String {
    let mut contents = String::new();
    for file in files {
        contents = format!("{}\\program{{{}}}{{{}}}", contents, file.name, get_normalized_path(project_path, &file.path));
    }

    contents
}

fn get_model(model_path: &Path) -> Result<String> {
    Ok(fs::read_to_string(model_path).context("An error occurred while reading model")?)
}

pub fn compile_latex(program: &CodeCompilation) -> Result<Vec<u8>> {
    // Check that the model is there:
    if !program.model.exists() {
        // return a new error
        return Err(anyhow!("The model {} was not found!", program.model.as_os_str().to_string_lossy()));
    }

    // We can then generate the variable contents, that will be used by the variable:
    let mut contents = format!(r#"
    \newcommand{{\projectname}}{{{}}}
    \newcommand{{\program}}[2]{{\gdef\prgname{{#1}}\gdef\prgpath{{#2}}}}
    \newcommand{{\includedFiles}}{{{}}}
    {}
    "#,
                               program.name,
                               get_included_files_contents(&program.contents, &program.project_path),
                               get_model(program.model.as_path())?);

    let mut files = {
        let mut status = TermcolorStatusBackend::new(ChatterLevel::Minimal);

        let config = PersistentConfig::default();

        let mut bundle = config
            .default_bundle(false, &mut status)
            .or(Err(anyhow!("An error occurred while downloading the bundle!")))?;

        let cache_path = config.format_cache_path()
            .map_err(|_| anyhow!("An error occurred while getting the format cache path"))?;

        // We can the include the contents
        let mut session_builder = ProcessingSessionBuilder::new_with_security(
            SecuritySettings::new(MaybeAllowInsecures)
        );

        // Create the filemanager
        let files = TempRepository::new(program)?;

        session_builder
            .primary_input_buffer(contents.as_bytes())
            .filesystem_root(&program.project_path)
            .keep_intermediates(false)
            .keep_logs(false)
            .output_format(OutputFormat::Pdf)
            .tex_input_name("texput.tex")
            .bundle(bundle)
            .format_name("latex")
            .format_cache_path(cache_path)
            .print_stdout(false)
            .shell_escape_with_work_dir(files.path())
            .do_not_write_output_files();

        let mut session = session_builder.create(&mut status)
            .or(Err(anyhow!("An error occurred while creating the session!")))?;

        session.run(&mut status).or(Err(anyhow!("An error occurred while compiling latex!")))?;

        session.into_file_data()
    };

    match files.remove("texput.pdf") {
        Some(file) => Ok(file.data),
        None => Err(anyhow!(
            "LaTeX didn't report failure, but no PDF was created (??)"
        )),
    }
}