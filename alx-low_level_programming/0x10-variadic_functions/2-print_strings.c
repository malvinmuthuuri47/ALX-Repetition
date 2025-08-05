#include "variadic_functions.h"

/**
 * print_strings - a variadic function that prints strings and a new line
 *
 * @separator: the char that separates strings
 * @n: the expected number of strings
 *
 * Return: Nothing
 */

void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str != NULL)
			printf("%s", str);
		else
			printf("(nil)");

		if (separator != NULL && i < n - 1)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}
