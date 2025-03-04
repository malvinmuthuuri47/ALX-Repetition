#include "main.h"

/**
 * _strcat - Function that concatenates two strings
 *
 * @dest: The pointer to the destination where the string is to be copied
 * @src: pointer to the location where the string is to be copied  from
 *
 * Return: A pointer to the destination containing the concatenated string
 */

char *_strcat(char *dest, char *src)
{
	/* Find the end of the destination string */
	char *dest_end = dest;

	while (*dest_end != '\0')
	{
		dest_end++;
	}

	/* Append the source string to the destination string */
	while (*src != '\0')
	{
		*dest_end = *src;
		dest_end++;
		src++;
	}

	/* Null-terminating the concatenated string */
	*dest_end = '\0';

	return (dest);
}
