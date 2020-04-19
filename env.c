#include "shell_header.h"

/**
* get_path - Search the path
* @word: word to search
* Return: list of tokens
*/
char **get_path(const char *word)
{
	int i, j, buffer = BUFFSIZE;
	char *ptr, *str;
	char *array;
	char **buff;

	str = malloc(buffer * sizeof(char));
	if (str == NULL)
	{
		perror("Memory error");
	}
	buff = malloc(buffer * sizeof(char *));
	if (!buff)
	{
		perror("Memory error");
	}
	i = 0;
	while (environ[i])
	{
		if (_strncmp(environ[i], word, 4) == 0)
		{
			ptr = environ[i];
			_strcpy(str, ptr);
			array = strtok(str, ":=");
			j = 0;
			while (array != NULL)
			{
				buff[j] = array;
				array = strtok(NULL, ":=");
				j++;
			}
			buff[j] = NULL;
			return (buff);
		}
		i++;
	}
	perror("Error");
	free(buff);
	free(str);
	return (0);
}
