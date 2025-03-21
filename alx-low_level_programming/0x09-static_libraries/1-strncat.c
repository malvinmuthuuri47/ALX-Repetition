#include "main.h"

/**
 * _strncat - main function that copies the source string
 * to the dest string upto n bytes
 *
 * @src: pointer to the source string which is to be copied
 * @dest: pointer to the destination string which is to be concatenated
 * @n: a number which defines the number of bytes to be copied
 * from the source string
 *
 * Return: A pointer to the destination string after concatenation is done
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	/* Find the end of the dest string */
	char *dest_end = dest;

	while (*dest_end != '\0')
	{
		dest_end++;
	}

	/* Append up to n characters from the source */
	/* string to the destination string */
	for (i = 0; i < n && *src != '\0'; i++)
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}

	/* Null terminate the concatenated string */
	*dest_end = '\0';

	return (dest);
}
