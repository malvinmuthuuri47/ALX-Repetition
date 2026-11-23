#include "main.h"

/**
 * clear_bit - function that sets a value of a bit to 0 at index
 *
 * @n: pointer to the memory address storing the int
 * @index: binary index for the bit to be flipped
 *
 * Return: 1 on success, -1 Otherwise
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL)
	{
		return (-1);
	}

	*n = *n & ~(1U << index);

	return (1);
}
