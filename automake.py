#!/usr/bin/env python3

import os
from pathlib import Path
import json

config = json.load(open("automakeconfig.json"))

def get(name, other):
    if name in config:
        return config[name]
    return other


def get_path():
    real_path = os.path.realpath(__file__)
    return Path(real_path).parent / get("path", "src")


def list_files():
    files = []
    for source_file in get_path().iterdir():
        # Filter dirs out
        if source_file.is_file():
            files.append(source_file)
    return files


def get_id(file: Path):
    return file.stem


def get_new_declaration(file):
    return "add_executable(PRG_" + get_id(file) + " " + get("path", "src") + os.sep + file.name + ")\n"


def generate(programs):
    buffer = ""
    with open(get("listsPath", "CMakeLists.txt"), 'r') as cmake_file:
        replacing = False
        for line in cmake_file.readlines():
            if not replacing:
                buffer += line
            if line.startswith("#make:auto"):
                replacing = True
                # Add the newly generated contents
                buffer += programs
                buffer += "#make:end"
            if line.startswith("#make:end"):
                replacing = False
    return buffer


def main():
    # We search all source files
    files = list_files()
    buffer = ""
    for file in files:
        buffer += get_new_declaration(file)

    file_contents = generate(buffer)
    with open(get("listsPath", "CMakeLists.txt"), 'w') as result_file:
        result_file.write(file_contents)

    print("Paramètres de compilation mis à jour!")


if __name__ == '__main__':
    main()
