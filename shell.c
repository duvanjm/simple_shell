#include "shell.h"
extern char **environ;
/**
 * split - Split the line on arguments
 * @buf: argument to divide.
 *
 * Return: divided arguments
 */
char **split(char *buf)
{
        char *command, *aux, *token, **arg;
        int i;

        command = _strdup(buf);
        aux = _strdup(buf);

        while (token != NULL)
        {
                i++;
                token = strtok(NULL, " \n");
        }
        arg = malloc(sizeof(char *) * (i + 1));
        for (i = 0, token = strtok(aux, " \n"); token; i++)
                arg[i] = _strdup(token), token = strtok(NULL, " \n");
        arg[i] = NULL;
        free(command);
        free(aux);

        return (arg);
}

/**
 * main - Simple Shell
 * Return: void
 */
int main(void)
{
        char *buffer, **arg;
        unsigned long int len, i;
        int line;
        pid_t pid;
        struct stat st;

        while (1)
        {
                _printString("#cisfun$ ");
                line = getline(&buffer, &len, stdin);
                if (line != -1)
                {
                        arg = split(buffer);
                        if (stat(arg[0], &st) == 0 && st.st_mode & S_IXUSR)
                        {
                                pid = fork();
                                if (pid == 0)
                                        execve(arg[0], arg, NULL);
                                else
                                        wait(NULL);
                        }
                        for (i = 0; arg[i]; i++)
                                free(arg[i]);
                        free(arg);
                }
                free(buffer);
                buffer = 0;
        }
        return (0);
}