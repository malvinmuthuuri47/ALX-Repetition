#include "function_pointers.h"

/**
 * int_index - function that takes elements of an array and executes
 * the function cmp on each element
 *
 * @array: pointer to the integer array in memory
 * @size: the size of the array
 * @cmp: the function to execute on each element of the array
 *
 * Return: Index of the array element that matches the function
 * condition and -1 otherwise
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
