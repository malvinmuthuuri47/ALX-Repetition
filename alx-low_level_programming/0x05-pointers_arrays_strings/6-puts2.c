#include "main.h"

/**
 * puts2 - main function to print parts of a string
 *
 * @str: The pointer to the location of the string in memory
 */

void puts2(char *str)
{
	int len = 0;
	int i;

	while (str[len] != '\0')
	{
		len++;
	}

	for (i = 0; i < len; i += 2)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
