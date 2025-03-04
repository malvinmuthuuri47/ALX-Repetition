#include "main.h"

/**
 * print_number - main function that uses recursion to print a number
 * by converting it to it's ASCII code equivalent
 *
 * @n: the number to be printed
 *
 * Return: none
 */

void print_number(int n)
{
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}

	if (n / 10)
	{
		print_number(n / 10);
	}

	_putchar((n % 10) + '0');
}
