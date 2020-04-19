#include "shell_header.h"
/**
* sh_execve - Execute the command
* @cmd: command to execute.
* Return: 1
*/
int sh_execve(char **cmd)
{
	pid_t pid;
	int status;
	char *tmp = NULL;
	char **path = NULL;

	path = rute();
	tmp = check_args(path, cmd, tmp);
	pid = fork();
	if (pid == 0)
	{
		execve_helper(cmd, path);
		if (!tmp)
		{
			free_ptr(path);
			free_ptr(cmd);
			exit(0);
		}
		if (execve(tmp, cmd, environ) == -1)
		{
			perror("Error execve");
			free_ptr(cmd);
			free(tmp);
			free_ptr(path);
			exit(1);
		}
		free(cmd);
		free_ptr(path);
	}
	else if (pid == -1)
	{
		free_ptr(path);
		free(cmd);
		perror("Error fork");
	}
	else
	{
		free_ptr(path);
		wait(&status);
	}
	return (1);
}

/**
* execve_helper - function that help in execve function
* @cmd: arguments the user
* @path: list
*/
void execve_helper(char **cmd, char **path)
{
	int i = 0;

	while (cmd[0][i]) /* recorre el comando mientras sea valido. */
	{
		if (cmd[0][i] == '/') /* si en la posicion [0][i] hay un slash */
		{
			free_ptr(path); /* libere la ruta */
			if (execve(cmd[0], cmd, environ) == -1) /* ejecute el comando */
			{
				perror("./hsh");
				free_ptr(cmd);
				exit(0);
			}
			free(cmd);
		}
		i++;
	}
}

/**
* check_args - check for arguments in the command
* @path: the path broken in different things
* @cmd: command to check for arguments
* @tmp: the value changed
* Return: the vale changed if it works
*/
char *check_args(char **path, char **cmd, char *tmp)
{
	int i = 1;

	while (path[i]) /* mientras la ruta en la posicion i sea valida */
	{
		/* concatene la ruta en la posicion i con el comando */
		_strcat(path[i], cmd[0]);
		if (access(path[i], X_OK) != -1) /* valida por permisos */
		{
			tmp = path[i];
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
