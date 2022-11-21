mod config;
mod cli;
mod commands;
mod latex;


use std::{fmt, fs};
use std::fs::read;
use std::path::PathBuf;
use std::process::exit;
use clap::Parser;
use anyhow::Result;
use console::{style, Style};
use similar::{ChangeTag, TextDiff};
use crate::cli::{Arguments, Subcommands};
use crate::latex::{CodeCompilation, CompilationFile, compile_latex};

struct Line(Option<usize>);

impl fmt::Display for Line {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self.0 {
            None => write!(f, "    "),
            Some(idx) => write!(f, "{:<4}", idx + 1),
        }
    }
}

fn main() -> Result<()> {
    let arguments = Arguments::parse();


    match arguments.subcommand {
        Subcommands::Test { .. } => {
            println!("Testing include with dummy data!");
            let context = CodeCompilation {
                name: "This is a test".to_string(),
                project_path: PathBuf::from("./"),
                model: PathBuf::from("./template.tex"),
                contents: vec![
                    CompilationFile {
                        name: "Example file".to_string(),
                        path: PathBuf::from("./src/main.rs"),
                    }
                ],
            };

            fs::write("./result.pdf",
                      compile_latex(&context)?)?;
        }
        Subcommands::Prepare { .. } => {}
        Subcommands::Submit { .. } => {
            println!("Submitting!")
        }
        Subcommands::New { .. } => {
            println!("New!")
        }
        Subcommands::Make { .. } => {
            println!("Make!")
        }
    }
    Ok(())
}