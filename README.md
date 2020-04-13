# Description
The simple shell is an application that reads lines from either a file or theterminal, interprets them, and executes them. This shell includes the basic functionality of a traditional Unix-like command line user interface. 
Standard functions and system calls employed in simple_shell include:
   `access, execve, exit, fork, free, getline, malloc, perror, signal, stat, wait, write.`

# Requirements

simple_shell is designed to run in the `Ubuntu 14.04.5 LTS` linux environment and to be compiled using the GNU compiler collection v. `gcc 4.8.4` with flags`-Wall, -Werror, -Wextra, and -pedantic.`

# Installation

   - Compile: `gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`
   - Run the shell in interactive mode: `./hsh`
   - Or run the shell in non-interactive mode:
   - example `echo "pwd" | ./hsh`

# Usage

The simple shell is an application that reads lines from either a file or theterminal, interprets them, and executes them. In a similar manner to sh, however with more limited functionality. 

# Examples

-`duvanjm@duvan-asus:~/holberton/simple_shell$ ./hsh
-#Cisfun$ ls
-Error: No such file or directory
-#Cisfun$ /bin/ls
-LICENSE  README.md  functions.c  hsh  man_1_simple_shell  shell.c  shell.h
-#Cisfun$ ^C
-duvanjm@duvan-asus:~/holberton/simple_shell$`

-`duvanjm@duvan-asus:~/holberton/simple_shell$ echo "/bin/ls" | ./hsh
-#Cisfun$ LICENSE  README.md  functions.c  hsh  man_1_simple_shell  shell.c  -shell.h
-duvanjm@duvan-asus:~/holberton/simple_shell$`

# Authors
Juan Felipe Rodriguez & Duvan Jaramillo.