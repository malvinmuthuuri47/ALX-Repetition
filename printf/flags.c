#include "main.h"

/**
 * parse_flags - a function that scans characters appearing after % in the
 * format string for the flags +, ' ', and #, sets them in the format_flags
 * struct, and returns a pointer to the next character.
 *
 * @fmt: pointer to the current position in the format string, just after
 * the %.
 * @flags: a pointer to a format_flags struct where the function stores which
 * flags are active
 *
 * Return: A pointer to the first character after all the flags, usually the
 * conversion specifier
 */
const char *parse_flags(const char *fmt, format_flags *flags)
{
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;

	while (*fmt == '+' || *fmt == ' ' || *fmt == '#')
	{
		if (*fmt == '+')
			flags->plus = 1;
		else if (*fmt == ' ')
			flags->space = 1;
		else if (*fmt == '#')
			flags->hash = 1;
		fmt++;
	}

	return (fmt);
}
