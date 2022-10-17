mod config;
mod cli;
mod commands;


use std::fmt;
use std::fs::read;
use std::process::exit;
use clap::Parser;

use console::{style, Style};
use similar::{ChangeTag, TextDiff};
use crate::cli::{Arguments, Subcommands};

struct Line(Option<usize>);

impl fmt::Display for Line {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self.0 {
            None => write!(f, "    "),
            Some(idx) => write!(f, "{:<4}", idx + 1),
        }
    }
}


fn main() {
    let arguments = Arguments::parse();


    match arguments.subcommand {
        Subcommands::Test { .. } => {
            todo!()
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
}