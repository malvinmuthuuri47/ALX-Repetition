#include "main.h"

/**
 * _puts - main function that prints a string to stdout
 *
 * @str: the pointer to the address of the string
 *
 */

void _puts(char *str)
{
	char *message = str;

	while (*message != '\0')
	{
		_putchar(*message);
		message++;
	}
	_putchar('\n');
}
