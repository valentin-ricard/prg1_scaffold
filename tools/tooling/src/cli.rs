use clap::{Args, Parser, Subcommand};

#[derive(Subcommand, Debug, Clone)]
pub enum Subcommands {
    /// Executes snapshot testing for a given program.
    Test {
        // At the moment, it doesn't take any argument.
    },
    /// Automatically updates the CMakeLists file to be up to date
    Prepare {
        // At the moment, it doesn't take any argument.
    },
    /// Generates a PDF file with the code contents,
    /// and creates a folder with both the source and the PDF for easy submission.
    Submit {
        // At the moment, it doesn't take any argument
    },
    /// Creates a new laboratory, with the proper header and generates the config file
    /// for the document generation.
    New {
        // As this command is interactive, there's no argument yet
    },
}

#[derive(Parser, Debug, Clone)]
#[clap(author = "Valentin Ricard", version, about = "Utilities to help with C++ classroom programming")]
pub struct Arguments {
    #[command(subcommand)]
    pub subcommand: Subcommands,

    /// Enables the debug output, useful for debugging.
    #[arg(short='D', long, default_value = "true")]
    pub debug: bool
}