#include "main.h"

/**
 * _strpbrk - function that searches a string for any set of bytes
 *
 * @s: pointer to the string in memory
 * @accept: the bytes to search for in the string
 *
 * Return: the first occurence of accept and all other letters
 *         that come after that.
 */

char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}
