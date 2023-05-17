# Line Duplicate Remover

This is a multi-threaded C++ program that reads lines from an input file and writes unique lines to an output file, removing duplicates in the process.

## Table of Contents

- [Usage](#usage)
- [Compilation](#compilation)
- [Requirements](#requirements)
- [Limitations](#limitations)
- [Strengths](#strengths)

## Usage

#### - Bash
```
./rm_dup <input_file> <output_file>
```
#### - Windows
```
rm_dup.exe <input_file> <output_file>
```

## Compilation

To compile the program, run the following command:

#### - Bash
```
g++ -o rm_dup rm_dup.cpp
```
#### - Windows
```
g++ -o rm_dup.exe rm_dup.cpp
```

## Execution

After compilation, you can run the program with the following command:

#### - Bash
```
./rm_dup <input_file> <output_file>
```
#### - Windows
```
rm_dup.exe <input_file> <output_file>
```


Replace `input.txt` and `output.txt` with the names of your input and output files, respectively.

## Requirements

- A C++17 compatible compiler (e.g., GCC or Clang)
- A POSIX-compatible operating system (e.g., Linux, macOS)

## Limitations

- The program assumes that there are no null characters ('\0') in the input file.
- The program loads the entire input file into memory, so it may not work well with very large input files.

## Strengths

- Multi-threaded design for improved performance on multi-core systems.
- Efficient removal of duplicate lines using an unordered set data structure.
