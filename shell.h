#ifndef SHELL
#define SHELL

    #include <sys/wait.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>

    /* shell.c */
    void shell_cicle(void);
    char *shell_read(void);
    char **shell_split(char *line);
    int shell_execute(char **args);

    /* functions.c */
    int _putchar(char c);
    int _strlen(char *s);
    void _printString(char *str);

#endif
