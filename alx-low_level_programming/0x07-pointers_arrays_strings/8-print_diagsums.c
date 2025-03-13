#include "main.h"

/**
 * print_diagsums - function that prints the sum of a
 *                  square matrix diagonals
 *
 * @a: the pointer to the first element of the flattened array
 * @size: the dimensions of the array
 *
 * Return: Nothing.
 */

void print_diagsums(int *a, int size)
{
	int primary_sum, secondary_sum, i;

	for (i = 0; i < size; i++)
	{
		primary_sum += a[i * size + i];
		secondary_sum += a[i * size + (size - i - 1)];
	}

	printf("%d, %d\n", primary_sum, secondary_sum);
}
