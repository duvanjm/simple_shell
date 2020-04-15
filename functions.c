#include "shell.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
   *_strlen - count the length of a string
   *
   *@s: string to count
   *
   *Return: length
   */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i += 1;
	}
	return (i);
}

/**
  *_printString - print a string
  *@str: string to print
  */
void _printString(char *str)
{
		int i = 0;

		while (str[i] != '\0')
		{
			_putchar(str[i]);
			i++;
		}
}
/**
   * _strcmp - check the code for Holberton School students.
    *	@s1: param
    *	@s2: param
     * Return: 0 if are equals, wathever if not.
      */
int _strcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0' ; i++)
	{
		if (s1[i] != s2[i])
		{
			j = s1[i] - s2[i];
			return (j);
		}
	}

	return (0);
}
