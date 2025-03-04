#include "main.h"

/**
 * puts_half - main function to print the upper split part of a string
 *
 * @str: The pointer to the string address in memory
 */

void puts_half(char *str)
{
	int len = 0;
	int i;

	while (str[len] != '\0')
	{
		len++;
	}

	if (len % 2 == 0)
	{
		for (i = len / 2; i < len; i++)
		{
			_putchar(str[i]);
		}
		_putchar('\n');
	}
	else
	{
		for (i = ((len - 1) / 2); i < len; i++)
		{
			_putchar(str[i]);
		}
		_putchar('\n');
	}
}
