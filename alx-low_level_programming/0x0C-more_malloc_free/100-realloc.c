#include "main.h"

/**
 * _realloc - custom implementation of realloc with the option of manually
 * passing the memory address as a parameter to know the original size
 * of allocated memory
 *
 * @ptr: pointer to the old memory address
 * @old_size: Size of the old memory block in bytes
 * @new_size: Size of the new memory block in bytes
 *
 * Return: Pointer to the new memory block, or NULL on failure
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, copy_size;
	unsigned char *new_ptr;
	unsigned char *old_ptr;

	old_ptr = (unsigned char *)ptr;

	/* realloc with NULL behaves like malloc */
	if (ptr == NULL)
		return (malloc(new_size));

	/* new size is 0 -> free memory and return NULL */
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	/* allocate new memory */
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	/* Determine hoe many bytes to copy */
	if (old_size < new_size)
		copy_size = old_size;
	else
		copy_size = new_size;

	/* copy bytes from old memory to new memory */
	for (i = 0; i < copy_size; i++)
		new_ptr[i] = old_ptr[i];

	/* free old memory */
	free(ptr);

	return (new_ptr);
}
