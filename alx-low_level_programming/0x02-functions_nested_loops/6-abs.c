#include "main.h"

/**
 * _abs - entry point
 *
 * @n: the num to look for the absolute value
 *
 * Return: the position of n with respect to 0 whether it is +ve or -ve
 *
 */

int _abs(int n)
{
	if (n < 0)
	{
		return (-n);
	}
	else
	{
		return (n);
	}
}
