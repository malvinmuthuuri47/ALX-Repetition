#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

/* structs */
typedef struct
{
	int plus;
	int space;
	int hash;
} format_flags;

/* Buffer Utils */
void flush_buffer(char *buffer, int *idx);
void buffer_putchar(char c, char *buffer,
		int *idx, int buf_size, int *total);
void buffer_puts(const char *s, char *buffer,
		int *idx, int buf_size, int *total);

/* String utils */
int my_strlen(const char *s);

/* Converters */
char *my_itoa(int n);
void my_putbin(unsigned int num, char *buffer, int *idx,
		int buf_size, int *total);
char *my_utoa(unsigned int num, int base, int uppercase);
char *my_ultoa_base(unsigned long num, int base, int uppercase);

/* Flags */
const char *parse_flags(const char *fmt, format_flags *flags);

/* Specifier Handler */
void handle_specifier(char spec, va_list args, char *buffer,
		int *idx, int buf_size, int *total, format_flags flags);

/* Main Print */
int _printf(const char *format, ...);

#endif

/* string_utils.c */
int my_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}

char *my_itoa(int n)
{
	char buf[12];
	int i, neg, j;
	unsigned int num;
	char *str;

	i = 0;
	neg = 0;

	if (n == 0)
	{
		str = (char *)malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	if (n < 0)
	{
		neg = 1;
		num = (unsigned int)(-n);
	}
	else
	{
		num = (unsigned int)n;
	}

	while (num > 0)
	{
		buf[i++] = (char)((num % 10) + '0');
		num /= 10;
	}

	if (neg)
		buf[i++] = '-';

	buf[i] = '\0';

	/* Reverse the string */
	str = (char *)malloc((size_t)i + 1);
	if (!str)
		return (NULL);

	for (j = 0; j < i; j++)
		str[j] = buf[i - j - 1];
	str[i] = '\0';

	return (str);
}

void my_putbin(unsigned int num, char *buffer, int *idx,
		int buf_size, int *total)
{
	char buf[(int)(sizeof(num) * 8) + 1];
	int i, j;

	i = 0;
	if (num == 0)
	{
		buffer_putchar('0', buffer, idx, buf_size, total);
		return;
	}

	while (num > 0)
	{
		buf[i++] = (char)(num & 1U) ? '1' : '0';
		num >>= 1;
	}

	for (j = i - 1; j >= 0; j--)
		buffer_putchar(buf[j], buffer, idx, buf_size, total);
}

char *my_utoa(unsigned int num, int base, int uppercase)
{
	static char buf[33];
	const char *digits_lc = "0123456789abcdef";
	const char *digits_uc = "0123456789ABCDEF";
	const char *digits = (uppercase ? digits_uc : digits_lc);
	int i;

	i = 32;
	buf[i] = '\0';

	if (num == 0U)
	{
		buf[--i] = '0';
		return (&buf[i]);
	}

	while (num > 0U && i > 0)
	{
		buf[--i] = digits[num % (unsigned int)base];
		num /= (unsigned int)base;
	}

	return (&buf[i]);
}

char *my_ultoa_base(unsigned long num, int base, int uppercase)
{
	static char buf[(int)(sizeof(unsigned long) * 2) + 1];
	const char *digits_lc = "0123456789abcdef";
	const char *digits_uc = "0123456789ABCDEF";
	const char *digits = (uppercase ? digits_uc : digits_lc);
	int i, max;

	max = (int)(sizeof(unsigned long) * 2);
	i = max;
	buf[i] = '\0';

	if (num == 0UL)
	{
		buf[--i] = '0';
		return (&buf[i]);
	}

	while (num > 0UL && i > 0)
	{
		buf[--i] = digits[(unsigned int)(num % (unsigned long)base)];
		num /= (unsigned long)base;
	}

	return (&buf[i]);
}

/* buffer_utils.c */
#include "main.h"

void flush_buffer(char *buffer, int *idx)
{
	if (*idx > 0)
	{
		write(1, buffer, *idx);
		*idx = 0;
	}
}

void buffer_putchar(char c, char *buffer,
		int *idx, int buf_size, int *total)
{
	if (*idx >= buf_size)
		flush_buffer(buffer, idx);

	buffer[(*idx)++] = c;
	(*total)++;
}

void buffer_puts(const char *s, char *buffer,
		int *idx, int buf_size, int *total)
{
	while (*s)
	{
		if (*idx > buf_size)
			flush_buffer(buffer, idx);

		buffer[(*idx)++] = *s++;
		(*total)++;
	}
}

/* converter.c */
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

/* flags.c */
#include "main.h"

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

/* specifier_handler.c */
#include "main.h"

/* _printf.c */
#include "main.h"

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
