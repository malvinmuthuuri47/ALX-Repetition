#include "main.h"

/**
 * print_triangle - function that takes triangle size and draws it
 *
 * @size: the parameter holding the actual size of the triangle
 */

void print_triangle(int size)
{
	int i, j, k;

	if (size > 0)
	{
		for (i = 1; i <= size; i++)
		{
			for (j = 1; j <= size - i; j++)
			{
				_putchar(32);
			}
			for (k = 1; k <= i; k++)
			{
				_putchar(35);
			}
			_putchar(10);
		}
	}
	else
	{
		_putchar(10);
	}
}
