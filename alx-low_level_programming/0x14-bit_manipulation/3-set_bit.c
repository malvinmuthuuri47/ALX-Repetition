#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at index
 *
 * @n: pointer to the memory location of the int
 * @index: bit location to convert to 1 in the int binary rep
 *
 * Return: 1 if sucessful, -1 otherwise
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL)
	{
		return (-1);
	}

	*n = (*n | (1U << index));

	return (1);
}
