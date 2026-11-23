#include "main.h"

/**
 * count_set_bits - takes an XOR operation and returns the number of
 * flipped bits
 *
 * @num: the result of an XOR operation
 *
 * Return: number of bits flipped
 */
unsigned int count_set_bits(unsigned long int num)
{
	unsigned long int count;

	count = 0;
	while (num > 0)
	{
		if (num & 1U)
		{
			count++;
		}

		num >>= 1;
	}

	return (count);
}

/**
 * flip_bits - returns the count of flipped bits by calling the
 * count_set_bits operator helper functions
 *
 * @n: the first number in the XOR operation
 * @m: the second number in the XOR operation
 *
 * Return: The count of flipped bits returned by the helper function
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	return (count_set_bits(n ^ m));
}
