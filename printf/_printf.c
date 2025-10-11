#include "main.h"


/**
 * _printf - the driver function that utilizes helper functions to mimic the
 * standard printf function
 *
 * @format: pointer to the specifier character to be checked
 *
 * Return: 0 on success, -1 otherwise
 */
int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int buf_idx, total;
	const char *p;

	buf_idx = 0;
	total = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	for (p = format; *p; p++)
	{
		if (*p == '%' && *(p + 1))
		{
			format_flags flags;

			p++;
			p = parse_flags(p, &flags);

			/* check if we have a valid specifier after flags */
			if (*p == '\0' || (*p != 'c' && *p != 's' && *p != 'd' && *p != 'i'
				&& *p != 'u' && *p != 'o' && *p != 'x' && *p != 'X' && *p != 'b'
				&& *p != '%' && *p != 'S' && *p != 'p'))
			{
				/* Invalid or incomplete specifier: do not print anything */
				return (-1);
			}
			handle_specifier(*p, args, buffer, &buf_idx, sizeof(buffer), &total, flags);
		}
		else
			buffer_putchar(*p, buffer, &buf_idx, sizeof(buffer), &total);
	}

	flush_buffer(buffer, &buf_idx);

	va_end(args);
	return (total);
}
