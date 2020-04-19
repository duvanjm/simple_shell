#include "shell_header.h"
/**
* main - simple shell
*
* Return: exit status
*/
int main(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, ctrl_c);

	do {
		if (isatty(STDIN_FILENO) == 1)
		{
			write(1, "~> ", 3);
		}
		line = shell_read();
		args = shell_parse(line);
		status = sh_exec(args);
		free(line);
		free(args);
	} while (status);

	return (0);
}

/**
* shell_read - get a line from the user
* Return: returns the text of the line readed
*/
char *shell_read(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == -1)
	{
		free(line);
		exit(0);
	}
	return (line);
}

/**
* shell_parse - split the string
*
* @line: line to split
*
* Return:  parsed line
*/
char **shell_parse(char *line)
{
	int i = 0;
	char *token;
	char **tokens;

	tokens = malloc(64 * sizeof(char *));
	if (!tokens)
	{
		perror("Error allocating memory");
		free(tokens);
		exit(1);
	}
	token = strtok(line, "\n\t\r\a ");

	while (token)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, "\n\t\r\a ");
	}
	tokens[i] = NULL;
	return (tokens);
}

/**
* ctrl_c - Handle CTRL+C
*
* @sig: signal
*/
void ctrl_c(int sig)
{
	(void)sig;
	_putchar('\n');
	write(1, "~> ", 3);
}
