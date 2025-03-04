#include "main.h"

/**
 * main - entry point
 *
 * Return: 0 on success
 * prints a string using the _putchar function
 */

int main(void)
{
	char str[] = "_putchar";
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
	return (0);
}
