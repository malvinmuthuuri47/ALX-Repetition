#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 *
 * @n: the integer to convert into binary
 * @index: the index to extract the bit at
 *
 * Return: the bit value at the index, -1 otherwise
 */
int get_bit(unsigned long int n, unsigned int index)
{
	return ((n >> index) & 1);
}
