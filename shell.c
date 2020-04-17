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
	char *line;
	char **args;
	char *shell_exit = "exit";
	int status;

	do {

		_printString("#Cisfun$ ");

		line = shell_read(); /* Read the line */

		if (*line == '\n') /* Validate if the command was a jump line */
		{
			continue;
		}

		args = shell_split(line); /* Split the line on arguments */

		/* Validate if the command was "exit" */
		if ((_strcmp(shell_exit, args[0])) == 0)
		{
			free(line);
			exit(0);
		}

		status = shell_execute(args); /* Execute the arguments*/

		free(line);
		free(args);
	} while (status);

	return (status == 0 ? 0 : 1);
}
/**
 * shell_read - Read the line of the standard input
 *
 * Return: argument of stdin.
 */
char *shell_read(void)
{
	char *str = NULL;
	size_t len = 0;
	int status;

	status = getline(&str, &len, stdin);

	if (status == EOF)
	{
		if (isatty(STDIN_FILENO))
		{
			_putchar('\n');
		}
		free(str);
		exit(0);
	}
	return (str);
}

/**
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
				free(tokens);
				perror("Error");
				exit(1);
			}
		}
		token = strtok(NULL, "\t\r\n\a");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
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
			perror(args[0]);
			exit(1);
		}
	}
	else if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (1);
}
