#include "main.h"

/**
 * _isalpha - main entry point
 *
 * @c: The character to be checked
 *
 * Return: if c is lowercase or uppercase, return 1, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
