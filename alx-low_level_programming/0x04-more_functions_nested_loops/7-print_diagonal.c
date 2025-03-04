#include "main.h"

/**
 * print_diagonal - entry point that prints a diagonal line and a preceding
 * space
 *
 * @n: The number of characters to print
 *
 * Return: none
 */

void print_diagonal(int n)
{
	int i, j;

	if (n <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
			{
				_putchar(' ');
			}
			_putchar(92);
			_putchar('\n');
		}
	}
}
