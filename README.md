# Simple Shell Program for Holberton School

## Description 
Simple Shell program that emulates a simpler `sh` command written in C.

**This project is for education purposes and it may not contain the best code or design practices.**

## Features

This program has basic features like executing commands from their name (if they are in the PATH), or if the user specifies the path for the executable binary.

**Example:** Both _"ls"_ and _"/bin/ls"_ will execute the `ls` program.

### Modes
This shell can be run in interactive mode, similiar to a command line interface. \
The "$ " prompt will appear when the user is asked for input and after a command has been executed.

> host@linux: ./hsh \
> $ ls \
> hsh main.c shell.c \
> $

But the program can also receive commands via piping (`|`), this the non-interactive mode.

> host@linux: echo "ls" | ./hsh \
> hsh main.c shell.c \
> host@linux:

### Builtins

`env`: Prints all environment variables. \
`exit`: Exits the shell.

## Compilation
The program can be compiled with: \
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`
