#include "main.h"

/**
 * _strchr - function that returns the first occurrence of char c in string s
 *
 * @s: the pointer to the string location in memory
 * @c: the character to look for in the string
 *
 * Return: pointer to the first occurrence of c in memory. Null otherwise
 */

char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
		{
			return (s);
		}
		s++;
	}

	return (NULL);
}
