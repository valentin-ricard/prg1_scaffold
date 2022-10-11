use serde::Deserialize;
use clap::Parser;

#[derive(Deserialize, Parser, Debug)]
pub struct Config {
    pub project: Project
}

pub struct Project {
    /// If this value is set to true, the harness will optimize the processing time by
    /// running more than one instance of the program at the same time.
    ///
    /// Note: This can break in pieces the instant you have some cache files, or expectations
    /// on locks, among others.
    #[serde(default)]
    pub atomic: bool,
    pub test_cases: Vec<String>,
    pub source_dir: Option<String>
}