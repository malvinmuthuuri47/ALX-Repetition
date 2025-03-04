#include "main.h"

/**
 * _strcmp - function that compares two strings
 *
 * @s1: pointer to the first string
 * @s2: pointer to the second string
 *
 * Return: 0 if both strings are equal, negative num if s1 is less
 * than s2, and a positive num if s1 is greater than s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
