#include "main.h"

/**
 * _puts_recursion - function that writes a string to stdout using recursion
 *
 * @s: pointer to the string in memory
 *
 * Return: Nothing.
 */

void _puts_recursion(char *s)
{
	/* base case: stop when the null byte is reached */
	if (*s == '\0')
	{
		_putchar('\n');
		return;
	}

	/* write the current character to stdout */
	_putchar(*s);

	/* Recursive call to handle next character */
	_puts_recursion(s + 1);
}
