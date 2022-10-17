use std::path::Path;
use serde::Deserialize;

#[derive(Deserialize)]
pub struct Config {
    pub source_dir: Option<Box<Path>>,
    pub cmake_path: Option<Box<Path>>
}