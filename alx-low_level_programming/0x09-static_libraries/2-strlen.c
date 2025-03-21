#include "main.h"

/**
 * _strlen - main function that counts the size of a string
 *
 * @s: The pointer to the address containing the string
 *
 * Return: total number of characters of the string
 */

int _strlen(char *s)
{
	int count = 0;

	while (s[count] != '\0')
	{
		count++;
	}
	return (count);
}
