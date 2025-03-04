#include "main.h"

/**
 * print_square - entry point of program to print a square using the #
 * symbol
 *
 * @size: The size of the square to print
 *
 * Return: none
 */

void print_square(int size)
{
	int i, j;

	if (size <= 0)
	{
		_putchar('\n');
	}
	else
	{
		for (i = 0; i < size; i++)
		{
			for (j = 0; j < size; j++)
			{
				_putchar('#');
			}
			_putchar('\n');
		}
	}
}
