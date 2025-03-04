#include "main.h"

/**
 * rot13 - function that encodes a string using rot13
 *
 * @str: the pointer to the string location in memory
 *
 * Return: pointer to the modified string
 */

char *rot13(char *str)
{
	char *ptr = str;

	while (*ptr)
	{
		if ((*ptr >= 'A' && *ptr <= 'Z'))
		{
			*ptr = ((*ptr - 'A' + 13) % 26) + 'A';
		}
		else if ((*ptr >= 'a' && *ptr <= 'z'))
		{
			*ptr = ((*ptr - 'a' + 13) % 26) + 'a';
		}
		ptr++;
	}

	return (str);
}

