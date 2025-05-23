#include "main.h"

/**
 * create_array - function that assigns memory dynamically on the heap
 * and fills the memory with a specific character
 *
 * @size: the memory size
 * @c: the character to fill the memory
 *
 * Return: character pointer to the beginning of the memory address
 */

char *create_array(unsigned int size, char c)
{
	unsigned int i;
	char *arr;

	if (size == 0)
	{
		return (NULL);
	}

	arr = malloc(sizeof(c) * size);
	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < size; i++)
	{
		arr[i] = c;
	}

	return (arr);
}
