#include "variadic_functions.h"

/**
 * print_numbers - a variadic function that prints numbers and a new line
 *
 * @separator: a character that acts as a separator between two nums
 * @n: the expected number of arguments to be passed to the function
 *
 * Return: Nothing.
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	int num;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		num = va_arg(args, int);
		printf("%d", num);

		if (i != n - 1 && separator != NULL)
			printf("%s", separator);
	}

	printf("\n");
	va_end(args);
}
