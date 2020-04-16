#ifndef SHELL
#define SHELL

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

    /* shell.c */
    char *shell_read(void);
    int shell_execute(void);
    char **split(char *buf);

    /* functions.c */
    int _putchar(char c);
    int _strlen(char *s);
    void _printString(char *str);
    int _strcmp(char *s1, char *s2);
    char *_strdup(char *str);

    /* _calloc.c */
    char *_memset(char *s, char b, unsigned int n);
    void *_calloc(unsigned int nmemb, unsigned int len);
#endif

