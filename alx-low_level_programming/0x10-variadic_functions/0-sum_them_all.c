#include "variadic_functions.h"

/**
 * sum_them_all - variadic function that returns the sum of all its parameters
 *
 * @n: the num of expected parameters
 *
 * Return: The sum of the params passed to the function
 */

int sum_them_all(const unsigned int n, ...)
{
	va_list args;
	unsigned int i, sum, num;

	if (n == 0)
		return (0);

	va_start(args, n);
	sum = 0;

	for (i = 0; i < n; i++)
	{
		num = va_arg(args, int);
		sum += num;
	}

	va_end(args);

	return (sum);
}
