#include "main.h"

/**
 * array_range - function that creates an array of integers and fills
 * the intermediate values with an increment of one till we give to
 * the max value starting from the min value
 *
 * @min: the min value
 * @max: the max value
 *
 * Return: A pointer to the newly created and populated integer array
 */
int *array_range(int min, int max)
{
	int *arr, i, size;

	if (min >= max)
		return (NULL);

	size = (max - min) + 1;
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		arr[i] = min + i;

	return (arr);
}
