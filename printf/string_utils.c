#include "main.h"

/**
 * my_strlen - function that returns the length of the string passed to it
 *
 * @s: pointer to the string
 *
 * Return: The length of the string
 */
int my_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
		len++;

	return (len);
}

/**
 * my_itoa - a function that converts an int to its equivalent ascii character
 *
 * @n: the integer to convert
 *
 * Return: The character equivalent of the int passed
 */
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

/**
 * my_putbin - function that converts an unsigned integer to a binary
 * and writes it to the buffer
 *
 * @num: the unsinged int
 * @buffer: pointer to the memory address where the converted int will
 * be stored
 * @idx: an iterator to iterate over the buffer
 * @buf_size: the buffer size
 * @total: total number of characters written to the buffer
 *
 * Return: void
 */
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

/**
 * my_utoa - a function that converts an unsigned integer to a string in
 * any base
 *
 * @num: the unsinged integer
 * @base: the base to convert the number to
 * @uppercase: a flag that's used to tell the function whether to convert
 * the integer to upper or lower case.
 *
 * Return: the converted integer as a string
 */
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

/**
 * my_ultoa_base - funciton that converts an unsigned long to a
 * string in any base
 *
 * @num: the num to convert
 * @base: the base to convert the number to
 * @uppercase: a flag that determines whether to convert the number
 * to upper/lower
 *
 * Return: the converted number as a string
 */
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
