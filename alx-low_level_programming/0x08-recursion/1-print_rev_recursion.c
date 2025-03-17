#include "main.h"

/**
 * _print_rev_recursion - function that prints a string in reverse order
 *
 * @s: pointer to the string in memory
 *
 * Return: Nothing.
 */

void _print_rev_recursion(char *s)
{
	/* base case: stop when null byte is reached */
	if (*s == '\0')
	{
		return;
	}

	/* recursive call to process next character in the string */
	_print_rev_recursion(s + 1);

	_putchar(*s);
}
