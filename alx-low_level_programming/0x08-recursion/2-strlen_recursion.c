#include "main.h"

/**
 * _strlen_recursion - function that calculates the length of a
 *                     string using recursion
 *
 * @s: pointer to the string memory address
 *
 * Return: the length of the string.
 */

int _strlen_recursion(char *s)
{
	/* base case: end of string */
	if (*s == '\0')
	{
		return (0);
	}

	return (1 + _strlen_recursion(s + 1));
}
