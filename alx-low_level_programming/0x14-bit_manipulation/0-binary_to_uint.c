#include "main.h"

/**
 * binary_to_uint - converts a binary number to unsigned int
 *
 * @b: string to be parsed into binary
 *
 * Return: The converted binary number, 0 otherwise
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result;
	unsigned int power;
	int i;
	int length;
	int digit;

	if (b == NULL)
	{
		return (0);
	}

	result = 0;
	power = 1;
	length = strlen(b);
	i = length - 1;

	while (i >= 0)
	{
		if (b[i] != '0' && b[i] != '1')
		{
			return (0);
		}

		digit = b[i] - '0';
		result += digit * power;

		power *= 2;
		i--;
	}

	return (result);
}
