use std::fs::{copy, create_dir_all, hard_link};
use std::os::unix::fs::symlink;
use std::path::{Path, PathBuf};
use anyhow::{anyhow, Context, Result};
use pathdiff::diff_paths;
use tempdir::TempDir;
use crate::latex::CodeCompilation;

pub fn get_normalized_path(project_path: &Path, file: &Path) -> String {
    diff_paths(file, project_path)
        .unwrap_or(PathBuf::from(file)).to_string_lossy().to_string()
}

pub struct TempRepository {
    // Kept here to make sure it is not dropped.
    path: TempDir,
}

impl TempRepository {
    #[cfg(windows)]
    fn copy_file(&self, source: &Path) -> Result<()> {
        // We are on windows, so we have to copy the actual contents (hardlinks could cause issues)
        copy(
            source,
            target,
        )?;
        Ok(())
    }

    #[cfg(not(windows))]
    fn copy_file(source: &Path, target: &Path) -> Result<()> {
        // As we are not on windows, symbolic links works
        symlink(
            source,
            target,
        )?;
        Ok(())
    }

    pub fn path(&self) -> &Path {
        self.path.path()
    }

    pub fn new(project: &CodeCompilation) -> Result<Self> {
        let path = TempDir::new("latex_compilation").context("An error occurred while creating the temporary directory")?;
        // Copy all files
        for file in &project.contents {
            let normalized_path = path.path().join(
                get_normalized_path(&project.project_path, &file.path));

            // As we are expecting it to be a file, we get the higher value
            let dir = normalized_path.parent()
                .ok_or(anyhow!("The path is not valid!"))?;
            if !dir.exists() {
                create_dir_all(&dir)?;
            }


            // Make sure we have created the entire hierarchy
            Self::copy_file(&file.path,
                            &normalized_path,
            )?;
        }

        // All

        Ok(TempRepository {
            path
        })
    }
}