#include "main.h"

/**
 * _strncpy - function that copies a string from src to dest upto
 * n bytes and adds null termination at the end of the string if
 * there are empty spaces
 *
 * @dest: the location the string is to be copied to
 * @src: the location the string is to be copied from
 * @n: the number of bytes of the string to be copied
 *
 * Return: a pointer to the destination string dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	for (; i < n; i++)
	{
		dest[i] = '\0';
	}
	return (dest);
}
