# <a href="url"><https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg width="100" height="100"></a> simple_shell

# Description
The simple shell is an application that reads lines from either a file or theterminal, interprets them, and executes them. This shell includes the basic functionality of a traditional Unix-like command line user interface. 
Standard functions and system calls employed in simple_shell include:
   `access, execve, exit, fork, free, getline, malloc, perror, signal, stat, wait, write.`

# Requirements

simple_shell is designed to run in the `Ubuntu 14.04.5 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

# Installation

   - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`
   - Run the shell in non-interactive mode:
   - Example `echo "pwd" | ./hsh`

# Usage

The simple shell is an application that reads lines from either a file or theterminal, interprets them, and executes them. In a similar manner to sh, however with more limited functionality. 

# Examples
```
$ ./hsh 
~> ls -l
total 76
-rw-rw-r-- 1 vagrant vagrant   217 Apr 19 18:27 AUTHORS
-rw-rw-r-- 1 vagrant vagrant  2147 Apr 19 18:27 aux_functions.c
-rw-rw-r-- 1 vagrant vagrant   737 Apr 19 18:27 built_ins.c
-rw-rw-r-- 1 vagrant vagrant   764 Apr 19 18:27 env.c
-rw-rw-r-- 1 vagrant vagrant  1766 Apr 19 18:27 _execve.c
-rw-rw-r-- 1 vagrant vagrant   935 Apr 19 18:27 free.c
-rwxrwxr-x 1 vagrant vagrant   331 Apr 19 18:27 generate_authors
-rwxrwxr-x 1 vagrant vagrant 21421 Apr 19 18:39 hsh
-rw-rw-r-- 1 vagrant vagrant  1069 Apr 19 18:27 LICENSE
-rwxrwxr-x 1 vagrant vagrant  1939 Apr 19 18:27 man_1_simple_shell
-rw-rw-r-- 1 vagrant vagrant   252 Apr 19 18:27 _putchar.c
-rw-rw-r-- 1 vagrant vagrant  1559 Apr 19 18:27 README.md
-rw-rw-r-- 1 vagrant vagrant  1125 Apr 19 18:39 shell_header.h
-rw-rw-r-- 1 vagrant vagrant  1196 Apr 19 18:27 shell_main.c
~> pwd
/home/vagrant/simple_shell
~> exit
$ 
```

# Authors
Duvan Jaramillo & Juan Felipe Rodriguez.