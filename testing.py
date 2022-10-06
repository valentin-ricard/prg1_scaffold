import subprocess
import sys
import re
import difflib as dl


def parse_input(path):
    with open(path) as file:
        input = ""
        output = ""
        status = ""
        for line in file.readlines():
            # Check the status
            if re.search("^ *>>>", line):
                status = "input"
                continue
            elif re.search("^ *<<<", line):
                status = "output"
                continue

            if status == "input":
                input += line
            elif status == "output":
                output += line

        return input, output


def execute_program(program_name, io):
    process = subprocess.Popen(program_name,
                               text=True,
                               shell=False,
                               bufsize=0,
                               stdin=subprocess.PIPE,
                               stdout=subprocess.PIPE,
                               stderr=subprocess.PIPE)
    process.stdin.write(io[0])
    output = process.stdout.read()
    # Compare contents, not details
    expected_output = io[1]

    list_diff = dl.SequenceMatcher(None, expected_output.splitlines(), output.replace(' \n', '\n').splitlines())

    if list_diff.ratio() >= 1.0:
        print("Success !!!")
    else:
        differences = dl.ndiff(expected_output.splitlines(), output.replace(' \n', '\n').splitlines(),
                               charjunk=lambda s: s == ' ')
        for difference in differences:
            print(difference)


if __name__ == '__main__':
    io = parse_input(sys.argv[1])
    execute_program("./cmake-build-debug/PRG_taxi", io)
