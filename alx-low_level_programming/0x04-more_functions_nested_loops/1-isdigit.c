#include "main.h"

/**
 * _isdigit - entry point checking if c is between char 0 and 9
 *
 * @c: The integer to be checked
 *
 * Return: 1 if true. 0 otherwise
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}
