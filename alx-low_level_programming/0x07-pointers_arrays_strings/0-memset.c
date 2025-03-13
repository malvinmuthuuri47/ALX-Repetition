#include "main.h"

/**
 * _memset - function that fills memory with a character
 *
 * @s: pointer to the memory address
 * @b: the character to fill in the memory
 * @n: the size of memory to fill with the character
 *
 * Return: pointer to the memory address
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
