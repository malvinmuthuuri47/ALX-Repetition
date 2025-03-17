#include "main.h"

/**
 * factorial - function that calculates the factorial of the
 *             number passed to it
 *
 * @n: the number
 *
 * Return: the factorial of the number or -1 otherwise
 */

int factorial(int n)
{
	/* base case */
	if (n < 0)
	{
		return (-1);
	}

	if ((n == 0) || (n == 1))
	{
		return (1);
	}

	return (n * factorial(n - 1));
}
