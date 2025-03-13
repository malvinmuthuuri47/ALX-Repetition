#include "main.h"

/**
 * _memcpy - function that copies some bytes from one memory location
 *           to another
 * @dest: the destination address to copy the bytes to
 * @src: the source of the bytes to be copied
 * @n: the size of the bytes to be copied
 *
 * Return: the pointer to the destination address where bytes are
 *         copied to
 */

char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
