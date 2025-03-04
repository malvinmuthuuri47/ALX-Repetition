#include "main.h"

/**
 * print_sign - entry point
 *
 * @n: the integer to be checked
 *
 * prints + if n is > 0
 * if n is equal to 0,
 * and minus if n is less than 0
 *
 * Return: 1 if n is positive, 0 if n == 0, -1 if n is less than 0
 */

int print_sign(int n)
{
	if (n > 0)
	{
		_putchar(43);
		return (1);
	}
	else if (n == 0)
	{
		_putchar(48);
		return (0);
	}
	else
	{
		_putchar(45);
		return (-1);
	}
}
