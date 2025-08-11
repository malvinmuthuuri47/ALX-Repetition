#include "main.h"

/**
 * my_strlen - a function that calculates the length of the string param
 *
 * @s: the string passed to the function
 *
 * Return: the length of the string
 */
static int my_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * my_puts - a function that writes a string to the standard output
 *
 * @s: the string address in memory
 *
 * Return: the number of bytes written to the standard output
 */
static int my_puts(const char *s)
{
	int len;

	len = my_strlen(s);
	if (len > 0)
		write(1, s, len);

	return (len);
}

/**
 * my_putchar - a function that writes a single character to stdout
 *
 * @c: the character to write
 *
 * Return: the number of bytes written (1 byte)
 */
static int my_putchar(char c)
{
	return (write(1, &c, 1));
}


/**
 * handle_specifier - a function that takes a format specifier, figures out
 * the type of arguments to fetch from args, prints them correctly using
 * the custom output functions, and returns the number of characters printed.
 *
 * @spec: the format specifier
 * @args: variadic argument passed to the function to match the specifiers
 *
 * Return: number of characters printed
 */
int handle_specifier(char spec, va_list args)
{
	char *str;

	if (spec == 'c')
		return (my_putchar((char)va_arg(args, int)));

	if (spec == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		return (my_puts(str));
	}

	if (spec == '%')
		return ((my_putchar('%')));

	my_putchar('%');
	return (1 + my_putchar(spec));
}

/**
 * _printf - a custom function meant to mimic the real printf
 *
 * @format: the format string to be passed
 *
 * Return: the total number of printed bytes.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int total;
	const char *p;

	if (!format)
		return (-1);

	va_start(args, format);
	total = 0;
	for (p = format; *p; p++)
	{
		if (*p == '%' && *(p + 1))
			total += handle_specifier(*++p, args);
		else
			total += my_putchar(*p);
	}

	va_end(args);
	return (total);
}
