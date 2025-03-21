#include "main.h"

/**
 * _isupper - Main entry point. Checks if the passed letter is uppercase
 *
 * @c: The integer to be checked
 *
 * Return: 0 if uppercase and 0 otherwise
 */

int _isupper(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}
