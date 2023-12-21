<br/>
<p>
  <a href="https://github.com/Ocyn/Pipex">
    <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/8/8d/42_Logo.svg/768px-42_Logo.svg.png" alt="Logo" width="80" height="80">
  </a>

  <h1>Pipex</h1>

  <p>
    42 School Project | Made in 2023 - 2024
    <br/>
    <br/>
  </p>
</p>

![Contributors](https://img.shields.io/github/contributors/Ocyn/Pipex?color=dark-green) ![Issues](https://img.shields.io/github/issues/Ocyn/Pipex) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Built With](#built-with)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Usage](#usage)
* [Authors](#authors)
* [Acknowledgements](#acknowledgements)

## About The Project

The `pipex` project involves managing pipes in a program that replicates the functionality of shell commands. The program is executed with the following format:
```bash
./pipex file1 cmd1 cmd2 file2
```

It takes four arguments:
file1 and file2 are file names.
cmd1 and cmd2 are shell commands with their parameters.
The program should behave exactly like the following shell command:
```bash
< file1 cmd1 | cmd2 > file2
```

## Project Structure

- **Source Files (`src/`):**
  - `pipex.c`: Main program logic and entry point.
  - Other supporting files for parsing, sorting, and utility functions.

- **Header File (`pipex.h`):**
  - Declarations of structures and function prototypes.

## Built With

* [C](https://en.wikipedia.org/wiki/C_(programming_language))

## Getting Started

**Compatibility Warning**
This project, **Pipex**, has primarily been developed and tested on a Linux Ubuntu system. It is essential to note that the project may encounter compatibility issues when executed on different operating systems. The utilization of Linux-specific features, libraries, or commands could lead to unexpected behavior on non-Linux platforms.

To ensure optimal performance and compatibility, it is recommended to run this project on a Linux environment, preferably Ubuntu. Attempting to execute the project on other operating systems may result in errors or unintended behavior.

Please consider this compatibility notice before proceeding with the compilation and execution of **Pipex**.

### Prerequisites

If you don't have Make
* Make

```sh
apt-get install build-essential make
```

### Installation

Clone the repo

```sh
git clone https://github.com/Ocyn/Pipex.git
cd Pipex/
```

### Compilation and Usage:

1. **Makefile:**
   - The project includes a Makefile with the following rules: `NAME`, `all`, `clean`, `fclean`, and `re`.

2. **Compilation:**
   - Compile the project using the provided Makefile.

  ```bash
  make
  ```

3. **Execution:**

Run the program with file names and shell commands.
```bash
./pipex infile "ls -l" "wc -l" outfile
```
4. **Expected Behavior:**

The program should replicate the behavior of the specified shell command.
**Generic Test Cases:**
  - Basic Test:
  Execute a simple command with no input or output redirection.
  ```bash
  ./pipex /dev/null "echo Hello" "wc -c" /dev/null
  ```
  - File Redirection:
  Use input and output redirection with files.
  ```bash
  ./pipex input.txt "cat" "grep something" output.txt
  ```
  - Command Chain:
  Execute a chain of commands using pipes.
  ```bash
  ./pipex input.txt "cat" "grep something | wc -l" output.txt
  ```
  **Specific Test Cases:**
  - Counting Lines:
  Count the number of lines in a file.
  ```bash
  ./pipex input.txt "cat" "wc -l" output.txt
  ```
  - Filtering Lines:
  Filter lines containing a specific pattern.
  ```bash
  ./pipex input.txt "cat" "grep pattern" output.txt
  ```
  - Sorting:
  Sort lines in a file.
  ```bash
  ./pipex input.txt "cat" "sort" output.txt
  ```
  - Word Count:
  Count the number of words in a file.
  ```bash
  ./pipex input.txt "cat" "wc -w" output.txt
  ```
  - Custom Command:
  Execute a custom command with parameters.
  ```bash
  ./pipex input.txt "cat" "awk '{print $2}'" output.txt
  ```
  - Invalid Command:
  Test error handling with an invalid command.
  ```bash
  ./pipex input.txt "cat" "invalid_command" output.txt
  ```
  - Empty Input File:
  Handle an empty input file.
  ```bash
  ./pipex empty.txt "cat" "wc -c" output.txt
  ```
  - Large File:
  Test performance with a large input file.
  ```bash
  ./pipex large_input.txt "cat" "grep pattern" large_output.txt
  ```
  - No Output File:
  Test without specifying an output file.
  ```bash
  ./pipex input.txt "cat" "grep pattern"
  ```
  - Missing Input File:
  Test when the input file is missing.
  ```bash
  ./pipex missing_input.txt "cat" "grep pattern" output.txt
  ```

6. **Clean Up:**

Clean up object files and executable.
```bash
make clean
```

## Program Instructions:
The program uses pipes and shell commands to replicate the functionality of the specified shell command.

**Input and Output Redirection:**
The program reads input from file1 and redirects it as input for the first shell command, cmd1.
Output from cmd1 is piped as input to the second shell command, cmd2.
The final output from cmd2 is redirected to file2.

# Execution Flow:
1. **Input Processing:**
- Reads the content of file1 to provide input to cmd1.

2. **First Command (cmd1):**
- Executes the first shell command specified by cmd1 using execve.
- Takes input from file1 and outputs to a pipe.

3. **Pipe Communication:**
- Uses a pipe to communicate between cmd1 and cmd2.
- Transfers the output of cmd1 to the input of cmd2.

4. **Second Command (cmd2):**
- Executes the second shell command specified by cmd2 using execve.
- Takes input from the pipe and outputs to file2.

**Example Execution:**
```bash
./pipex infile "ls -l" "wc -l" outfile
```
- Reads the content of infile.
- Executes ls -l and pipes the output to wc -l.
- The final result is written to outfile.

**Error Handling:**
- The program incorporates error handling for various scenarios, such as failed system calls, file access issues, and unexpected behavior.

**Cleanup**:
- Ensures proper cleanup by closing file descriptors, waiting for child processes to finish, and freeing allocated memory.

## Rules and Requirements:
The project must be written in C and adhere to the Norme.
Functions should not terminate unexpectedly, and no memory leaks are tolerated.
Error handling must be implemented sensibly.
The program must handle pipes, input and output redirection, and execute shell commands.
A Makefile must be provided for compilation.
Detailed instructions and examples are provided in the project description.

Follow the provided instructions in the README file for successful compilation and execution of the program.

## Authors

* **Ocyn** - *A Random Dev* - [Ocyn](https://github.com/Ocyn) - *Made the project*

## Acknowledgements

* [42 School](https://github.com/42School)
