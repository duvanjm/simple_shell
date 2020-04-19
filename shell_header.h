#ifndef SHELL
#define SHELL

	#include <stdio.h>
	#include <stdlib.h>
	#include <unistd.h>
	#include <string.h>
	#include <sys/types.h>
	#include <sys/wait.h>

	#define BUFFSIZE 1024

	extern char **environ;

	/* shell_main.c */
	char *shell_read(void);
	char **shell_parse(char *line);
	void ctrl_c(int sig);

	/* aux_functions */
	char *_strcat(char *dest, char *src);
	int _strcmp(char *s1, char *s2);
	int _strncmp(char *s1, const char *s2, int n);
	char *_strcpy(char *dest, char *src);
	char **rute(void);

	/* _putchar.c */
	int _putchar(char c);

	/* builtins.c */
	int sh_exit(char **args);
	int sh_exec(char **args);

	/* free.c */
	void free_ptr(char **ptr);
	void *_calloc(unsigned int nmemb, unsigned int size);
	char *_memset(char *s, char b, unsigned int n);


	/* env.c */

		/* path variables */
		char **get_path(const char *name);

	/* _execve.c */

		/*execute the command */
		int sh_execve(char **args);

		/* execute the command with arguments */
		void execve_helper(char **args, char **bin);

		/* check if the command have arguments */
		char *check_args(char **bin, char **args, char *tmp);
#endif
