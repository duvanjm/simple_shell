#include "shell_header.h"

/**
* sh_exit - exits from the shell
* @args: the argument written in the shell.
* Return: 1
*/
int sh_exit(char **args)
{
	(void)args;
	return (0);
}

/**
* sh_exec - start the builint cases
* @args: compare the args is a builint
* Return: the builint or sh_execve if is not a builint
*/
int sh_exec(char **args)
{
	char *arrayBuilint[] = {
		"exit",
		NULL};
	int (*built_intFunc[])(char **) = {&sh_exit};
	int i = 0;
	int sh_num_builtins = 0;

	sh_num_builtins = sizeof(built_intFunc) / sizeof(char *);

	if (args[0] == NULL)
	{
		return (1);
	}
	while (i < sh_num_builtins)
	{
		if (_strcmp(args[0], arrayBuilint[i]) == 0)
		{
			return (built_intFunc[i](args));
		}
		i++;
	}
	return (sh_execve(args));
}
