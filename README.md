<h3 align="center">
  0x16. C - Simple Shell
</h3>

<p align="center">
  <strong>
   Description
  </strong>
</p>

<p align="center">
This project is an implementation of the shell created as a Milestone Project for the C code at ALX Africa Software Engineering. </br>
This program was written entirely in C Language.
</p>

## COPYRIGHT
Copyright (C) 2023 by [**NIYOMWUNGERI Enock**](https://github.com/EnockNiyo) and [**NIYONGABO Jean Pierre**](https://github.com/ngabo-dev) </br>
All rights reserved

 ## Description :
This is a shell written in [C](https://en.wikipedia.org/wiki/C_(programming_language)).
It is based on [the Thompson Shell](https://en.wikipedia.org/wiki/Thompson_shell).

## Environment :

Our shell was built and tested on  Ubuntu 14.04 LTS.

## Features
* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Hndling the “end of file” condition (Ctrl+D)
* Hanling the command line with arguments
* Handle the PATH
* Support the exit features and the exit status
* Handle the Ctrl-C to not terminate the shell
* Handling the command seperator `;`
* Handling `&&` and `||` logical operators
* Handle variable replacements `$?` and `$$`
* Handle the comments `#`
* Support the history feature
* Support the file input

## Builtins
Our shell has support for the following built-in commands:

| Command             | Definition                                                                                |
| ------------------- | ----------------------------------------------------------------------------------------- |
| exit [n]            | Exit the shell, with an optional exit status, n.                                          |
| env                 | Print the environment.                                                                    |
| setenv [var][value] | Set an environment variable and value. If the variable exists, the value will be updated. |
| alias[name[='value]]| Reads aliases name                                                                        |
| unsetenv [var]      | Remove an environment variable.                                                           |
| cd [dir]            | Change the directory.                                                                     |
| help [built-in]     | Read documentation for a built-in.                                                        |


 
## Contributors

* [**NIYOMWUNGERI Enock**](https://github.com/EnockNiyo)
* [**NIYONGABO Jean Pierre**](https://github.com/ngabo-dev)

## Acknowledgments :
- The creators of the C language.
- Our software engineer-in-residence.
- Betty Holberton | Alx-Africa .
