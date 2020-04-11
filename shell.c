#include "shell.h"
/**
 * main - Simple Shell
 * @: Number of arguments
 * @: Valor of the arguments.
 *
 * Return: 0 if success, 1 if fail.
 */
int main(/*int ac, char const **av*/ void)
{
	shell_cicle(); /* Principal loop */

	return (0);
}
/**
 * shell_cicle - Simple Shell principal loop, read, split and execute.
 *
 * Return: Void.
 */
void shell_cicle(void)
{
	char *line;
	char **args;
	int status;

	do {
		_printString("#Cisfun$ ");
		line = shell_read();		  /* Read the line */
		args = shell_split(line);	  /* Split the line on arguments */
		status = shell_execute(args); /* Execute the arguments*/

		free(line);
		free(args);
	} while (status);
}

/**
 * shell_read - Read the line of the standard input
 *
 * Return: argument of stdin.
 */
char *shell_read(void)
{
	char *line;
	size_t len = 0;
	int status;

	status = getline(&line, &len, stdin);

	if (status == -1)
	{
		exit(EXIT_FAILURE);
	}
	return (line);
}

/*
 * shell_split - Split the line on arguments
 * @line: argument to divide.
 *
 * Return: divided arguments
 */
char **shell_split(char *line)
{
	int buffSize = 1024;
	int i = 0;
	char *token;
	char **tokens = malloc(sizeof(char) * buffSize);

	if (!tokens)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, "\t\r\n\a");

	while (token)
	{
		tokens[i] = token;
		i++;

		if (i >= buffSize)
		{
			tokens = realloc(tokens, buffSize * sizeof(char *));

			if (!tokens)
			{
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, "\t\r\n\a");
	}
	tokens[i] = NULL;

	return (tokens);
}

/*
 * shell_execute - Execute the arguments
 * @args: argument to divide
 *
 * Return: divided arguments.
 */
int shell_execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
		}
	}
	else if (pid < 0)
	{
		return (EXIT_FAILURE);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
