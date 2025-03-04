#include "main.h"

/**
 * _strcpy - main function that implements logic to copy a string stored
 * in one memory address to another memory address block
 *
 * @dest: This is the place to copy the string to
 * @src: This is the place that stores the string to be copied
 *
 * Return: the starting pointer address of the destination copied string
 */

char *_strcpy(char *dest, char *src)
{
	char *origin_pointer = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';

	return (origin_pointer);
}
