#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

/* custom function to flush buffer content */
static void flush_buffer(char *buffer, int *idx)
{
	if (*idx > 0)
	{
		write(1, buffer, *idx);
		*idx = 0;
	}
}

/* custom function to write a single character to a buffer */
static void buffer_putchar(char c, char *buffer, int *idx, int buf_size)
{
	if (*idx >= buf_size)
		flush_buffer(buffer, idx);
	buffer[(*idx)++] = c;
}

/* custom function to write a string to buffer */
static void buffer_puts(const char *s, char *buffer, int *idx, int buf_size)
{
	while (*s)
	{
		if (*idx >= buf_size)
			flush_buffer(buffer, idx);
		buffer[(*idx)++] = *s++;
	}
}

/* custom strlen: counts length of null-terminated string */
static int my_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}

/* custom function that converts an int to string (base 10), returns malloc'ed string */
static char *my_itoa(int n)
{
	char buf[12];
	int i, neg, j;
	unsigned int num;
	char *str;

	if (n == 0)
	{
		str = malloc(2);
		if (!str)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}

	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	else
		num = n;

	while (num > 0)
	{
		buf[i++] = (num % 10) + '0';
		num /= 10;
	}

	if (neg)
		buf[i++] = '-';

	buf[i] = '\0';

	/* Reverse the string */
	str = malloc(i + 1);
	if (!str)
		return (NULL);

	for (j = 0; j < i; j++)
		str[j] = buf[i - j - 1];
	str[i] = '\0';

	return (str);
}

/* helper function to convert unsigned int to binary string */
static void my_putbin(unsigned int num, char *buffer, int *idx, int buf_size)
{
	char buf[sizeof(num) * 8 + 1];
	int i, j;

	i = 0;
	if (num == 0)
	{
		buffer_putchar('0', buffer, idx, buf_size);
		return;
	}
	while (num > 0)
	{
		buf[i++] = (num & 1) ? '1' : '0';
		num >>= 1;
	}

	for (j = i - 1; j >= 0; j--)
		buffer_putchar(buf[j], buffer, idx, buf_size);
}

/* function that handles converting a number to a different base */
static char *my_utoa(unsigned int num, int base, int uppercase)
{
	static char buf[33];
	const char *digits_lc = "0123456789abcdef";
	const char *digits_uc = "0123456789ABCDEF";
	const char *digits = uppercase ? digits_uc : digits_lc;
	int i;

	i = 32;
	buf[i] = '\0';

	if (num == 0)
	{
		buf[--i] = '0';
		return (&buf[i]);
	}

	while (num > 0 && i > 0)
	{
		buf[--i] = digits[num % base];
		num /= base;
	}

	return (&buf[i]);
}

/* Helper function dealing with the specifiers */
static void handle_specifier(char spec, va_list args, char *buffer, int *idx, int buf_size)
{
	char *str;
	int num;
	unsigned int val;

	if (spec == 'c')
	{
		buffer_putchar((char)va_arg(args, int), buffer, idx, buf_size);
		return;
	}

	if (spec == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		buffer_puts(str, buffer, idx, buf_size);
		return;
	}

	if (spec == 'd' || spec == 'i')
	{
		num = va_arg(args, int);
		str = my_itoa(num);
		if (!str)
			return;
		buffer_puts(str, buffer, idx, buf_size);
		free(str);
		return;
	}

	if (spec == 'u')
	{
		val = va_arg(args, unsigned int);
		buffer_puts(my_utoa(val, 10, 0), buffer, idx, buf_size);
		return;
	}

	if (spec == 'o')
	{
		val = va_arg(args, unsigned int);
		buffer_puts(my_utoa(val, 8, 0), buffer, idx, buf_size);
		return;
	}

	if (spec == 'x')
	{
		val = va_arg(args, unsigned int);
		buffer_puts(my_utoa(val, 16, 0), buffer, idx, buf_size);
		return;
	}

	if (spec == 'X')
	{
		val = va_arg(args, unsigned int);
		buffer_puts(my_utoa(val, 16, 1), buffer, idx, buf_size);
		return;
	}

	if (spec == 'b')
	{
		my_putbin(va_arg(args, unsigned int), buffer, idx, buf_size);
		return;
	}

	if (spec == '%')
	{
		buffer_putchar('%', buffer, idx, buf_size);
		return;
	}

	buffer_putchar('%', buffer, idx, buf_size);
	buffer_putchar(spec, buffer, idx, buf_size);
}

int _printf(const char *format, ...)
{
	va_list args;
	char buffer[1024];
	int buf_idx;
	const char *p;

	buf_idx = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	for (p = format; *p; p++)
	{
		if (*p == '%' && *(p + 1))
			handle_specifier(*++p, args, buffer, &buf_idx, sizeof(buffer));
		else
			buffer_putchar(*p, buffer, &buf_idx, sizeof(buffer));
	}

	flush_buffer(buffer, &buf_idx);

	va_end(args);
	return (0);
}

int main(void)
{
	int len, len2;
	char *str = "When you invoke GCC, it normally does preprocessing, compilation, assembly and linking. The \"overall options\" allow you to stop this process at an intermediate stage. For example, the -c option says not to run the linker. Then the output consists of object files output by the assembler.\n\nOther options are passed on to one stage of processing. Some options control the preprocessor and others the compiler itself. Yet other options control the assembler and linker; most of these are not documented here, since you rarely need to use any of them.\n\nMost of the command line options that you can use with GCC are useful for C programs; when an option is only useful with another language (usually C ++ ), the explanation says so explicitly. If the description for a particular option does not mention a source language, you can use that option with all supported languages.\n\nThe gcc program accepts options and file names as operands. Many options have multi-letter names; therefore multiple single-letter options may not";

	len = _printf(str);
	len2 = _printf(str);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
