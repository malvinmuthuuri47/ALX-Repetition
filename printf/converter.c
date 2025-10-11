#include "main.h"

void handle_specifier(char spec, va_list args, char *buffer,
		int *idx, int buf_size, int *total, format_flags flags)
{
	char *str, *hex;
	void *ptr;
	int num;
	unsigned int val;
	unsigned char c;
	unsigned long addr;

	str = NULL;
	hex = NULL;
	ptr = NULL;
	num = 0;
	val = 0U;
	c = (unsigned char)0;
	addr = 0UL;

	if (spec == 'c')
	{
		buffer_putchar((char)va_arg(args, int), buffer, idx, buf_size, total);
		return;
	}

	if (spec == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		buffer_puts(str, buffer, idx, buf_size, total);
		return;
	}

	if (spec == 'd' || spec == 'i')
	{
		num = va_arg(args, int);
		str = my_itoa(num);
		if (!str)
			return;

		if (num >= 0)
		{
			if (flags.plus)
				buffer_putchar('+', buffer, idx, buf_size, total);
			else if (flags.space)
				buffer_putchar(' ', buffer, idx, buf_size, total);
		}

		buffer_puts(str, buffer, idx, buf_size, total);
		free(str);

		return;
	}

	if (spec == 'u')
	{
		val = va_arg(args, unsigned int);
		buffer_puts(my_utoa(val, 10, 0), buffer, idx, buf_size, total);
		return;
	}

	if (spec == 'o')
	{
		val = va_arg(args, unsigned int);
		if (flags.hash && val != 0U)
			buffer_putchar('0', buffer, idx, buf_size, total);
		buffer_puts(my_utoa(val, 8, 0), buffer, idx, buf_size, total);
		return;
	}

	if (spec == 'x')
	{
		val = va_arg(args, unsigned int);
		if (flags.hash && val != 0U)
			buffer_puts("0x", buffer, idx, buf_size, total);
		buffer_puts(my_utoa(val, 16, 0), buffer, idx, buf_size, total);
		return;
	}

	if (spec == 'X')
	{
		val = va_arg(args, unsigned int);
		if (flags.hash && val != 0U)
			buffer_puts("0X", buffer, idx, buf_size, total);
		buffer_puts(my_utoa(val, 16, 1), buffer, idx, buf_size, total);
		return;
	}

	if (spec == 'b')
	{
		my_putbin(va_arg(args, unsigned int), buffer, idx, buf_size, total);
		return;
	}

	if (spec == '%')
	{
		buffer_putchar('%', buffer, idx, buf_size, total);
		return;
	}

	if (spec == 'S')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";

		while (*str)
		{
			c = (unsigned char)*str;
			if (c < 32U || c >= 127U)
			{
				buffer_putchar('\\', buffer, idx, buf_size, total);
				buffer_putchar('x', buffer, idx, buf_size, total);

				hex = my_utoa((unsigned int)c, 16, 1);

				/* Ensure 2-digit hex */
				if (hex[1] == '\0')
					buffer_putchar('0', buffer, idx, buf_size, total);

				buffer_puts(hex, buffer, idx, buf_size, total);
			}
			else
				buffer_putchar((char)c, buffer, idx, buf_size, total);
			str++;
		}
		return;
	}

	if (spec == 'p')
	{
		ptr = va_arg(args, void *);
		if (ptr == NULL)
		{
			buffer_puts("(nil)", buffer, idx, buf_size, total);
			return;
		}

		addr = (unsigned long)ptr;
		buffer_puts("0x", buffer, idx, buf_size, total);
		hex = my_ultoa_base(addr, 16, 0);
		buffer_puts(hex, buffer, idx, buf_size, total);
		return;
	}

	/* unknown specifier: print it literally */
	buffer_putchar('%', buffer, idx, buf_size, total);
	buffer_putchar(spec, buffer, idx, buf_size, total);
}
