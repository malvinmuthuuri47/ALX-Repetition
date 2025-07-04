#include "main.h"

/**
 * _calloc - function that allocates memory for an array using malloc
 *
 * @nmemb: the number of elements in the array
 * @size: the size of each element in the array
 *
 * Return: A pointer to the newly allocated memory address of the array
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int total_size, i;
	unsigned char *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);

	total_size = nmemb * size;

	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);

	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);

	/* manually zero the memory */
	for (i = 0; i < total_size; i++)
		ptr[i] = 0;

	return (ptr);
}
