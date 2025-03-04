#include "main.h"

/**
 * print_numbers - entry point to print numbers 0 through 9
 *
 * Return: none
 */

void print_numbers(void)
{
	int i;

	for (i = '0'; i <= '9'; i++)
	{
		_putchar(i);
	}
	_putchar('\n');
}
