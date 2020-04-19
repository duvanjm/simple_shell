#include "shell_header.h"

/**
* *_strcat - concatenates two strins.
* @dest: destiny.
* @src: source.
* Return: the concatenates string.
*/

char *_strcat(char *dest, char *src)
{
	char *start = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}
/**
 * _strcmp - compare two strings and print the difference between the two
 *@s1: get the first string
 *@s2: get the second string
 * Return: return the diference between the two strings
 */
int _strcmp(char *s1, char *s2)
{
	int len;

	for (len = 0; s1[len] != '\0' || s2[len] != '\0'; len++)
	{
		if (s1[len] != s2[len])
		{
			return (s1[len] - s2[len]);
		}
	}
	return (*s1 - *s2);
}

/**
* _strncmp - compares at most the first n bytes of str1 and str2
* @s1: the first string to be compared
* @s2: the second string to be compared
* @n: the maximun number of character to be compared
* Return: return 0 if the strings are equals
*/

int _strncmp(char *s1, const char *s2, int n)
{
	int i, res = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}
	return (res);
}

/**
* _strcpy - copies the string pointed to by src,
* including the terminating null byte (\0),
* to the buffer pointed to by dest
* @src: source
* @dest: destination
*
* Return: the pointer to dest
*/

char *_strcpy(char *dest, char *src)
{
	int i, size;

	i = 0;
	size = 0;

	while (src[i] != '\0')
	{
		i++;
	}
	size = i;

	for (i = 0; i <= size; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}

/**
* rute - divide the path
* Return: return a list with /
*/
char **rute(void)
{
	int i = 0;
	char *path;
	char **ptr;
	char **list = NULL;

	ptr = get_path("PATH");
	list = _calloc(1024, sizeof(char));
	if (!list)
	{
		return (NULL);
	}
	path = malloc(sizeof(char) * 500);
	if (!path)
	{
		return (NULL);
	}

	while (ptr[i])
	{
		_strcpy(path, ptr[i]);
		_strcat(path, "/");
		list[i] = malloc(sizeof(char) * 1024);

		if (!list[i])
		{
			perror("memory error");
			return (NULL);
		}

		_strcpy(list[i], path);
		i++;
	}
	free(ptr[0]);
	free(ptr);
	free(path);
	return (list);
}
