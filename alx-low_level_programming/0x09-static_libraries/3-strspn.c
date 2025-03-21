#include "main.h"

/**
 * _strspn - function that gets the length of a prefix substring
 *
 * @s: pointer to the string in memory
 * @accept: the prefix substring
 *
 * Return: length of the prefix substring found in s
 */

unsigned int _strspn(char *s, char *accept)
{
	unsigned int count;
	int match;
	char *a;

	while (*s)
	{
		match = 0;

		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				match = 1;
				break;
			}
		}
		if (!match)
		{
			break;
		}
		count++;
		s++;
	}

	return (count);
}
