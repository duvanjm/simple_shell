#include "shell_header.h"

/**
* free_ptr - function that free double pointers
* @ptr: double pointer to free
*/

void free_ptr(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

/**
 * _memset - fills the first n bytes of the memory
 * area pointed to by s with the constant byte b
 * @s: pointer to memory
 * @b: byte to fill.
 * @n: first n bytes
 *
 * Return: pointer to memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		s[i] = b;
	}
	return (s);
}

/**
 * _calloc - allocates memory using malloc.
 *
 * @nmemb: sizeof type
 * @size: number of items
 * Return: Always 0.
 * if fails null
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *mem;

	if (nmemb == 0 || size == 0)
		return (0);

	mem = malloc(nmemb * size);
	if (mem == 0)
		return (0);
	mem = _memset(mem, 0, nmemb * size);
	return (mem);
}
