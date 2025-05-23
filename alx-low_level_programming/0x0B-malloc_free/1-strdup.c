#include "main.h"

/**
 * _strdup - function that makes a copy of a string passed to it and
 * duplicates it in memory by creating space for it in the heap
 *
 * @str: the string to be duplicated
 *
 * Return: A pointer to the memory address of the duplicated string
 * and NULL otherwise
 */

char *_strdup(char *str)
{
	unsigned int len, i;
	char *dupStr;

	if (!str)
	{
		return (NULL);
	}

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}

	dupStr = malloc(sizeof(*str) * (len + 1));
	if (!dupStr)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		dupStr[i] = str[i];
	}
	dupStr[len] = '\0';

	return (dupStr);
}
