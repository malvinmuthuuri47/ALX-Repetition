#include "main.h"

/**
 * print_line - entry point to print '_' n times and '\n' if n is
 * less than or equal to zero
 *
 * @n: The integer with the frequency to be used to print the character
 *
 * Return: None
 */

void print_line(int n)
{
	int i;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i <= n; i++)
		{
			_putchar('_');
		}
		_putchar('\n');
	}
}
