#include "main.h"

/**
 * print_alphabet_x10 - Entry point
 *
 * prints the lowercase alphabets 10 times
 *
 * Return: void
 */

void print_alphabet_x10(void)
{
	int i;
	int j;

	for (i = 0; i <= 9; i++)
	{
		for (j = 97; j <= 122; j++)
		{
			_putchar(j);
		}
		_putchar('\n');
	}
}
