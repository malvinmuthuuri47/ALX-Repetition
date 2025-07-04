#include "main.h"

/**
 * malloc_checked - function that allocates memory using \
 * malloc depending on size
 *
 * @b: the size of the memory
 *
 * Return: pointer to the allocated memory address, \
 * otherwise exit with custom exit code
 */

void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
	{
		exit(98);
	}

	return (ptr);
}
