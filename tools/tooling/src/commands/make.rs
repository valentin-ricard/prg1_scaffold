use std::fs::File;
use std::io::{BufRead, BufReader};
use std::path::{Path, PathBuf};
use std::sync::Arc;
use crate::config::Config;
use anyhow::{Context, Result};

/// Port of automake.py
/// This allows for easy modification of the CMakeLists.txt
/// file to include all programs in the configured source directory ("./src")
pub fn make(config: Arc<Config>) -> Result<()> {
    // We open the make file
    let original_file = File::open(
        config.cmake_path.map(PathBuf::from).unwrap_or(PathBuf::from("./CMakeLists.txt"))
    ).context("The original CMakeLists.txt file doesn't exists, or the program doesn't have the necessary permissions.")?;
    let buf_reader = BufReader::new(original_file);
    buf_reader.lines()
        .take()

}