#include "function_pointers.h"

/**
 * array_iterator - function that takes an array and a function and
 * executes the function on each of the array elements
 *
 * @array: the array
 * @size: the size of the array
 * @action: the function to execute on each array element
 *
 * Return: Nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
