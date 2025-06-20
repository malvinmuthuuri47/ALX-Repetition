#include "main.h"

/**
 * my_strlen - custom function that calculates the length of a string
 *
 * @s: the string
 *
 * Return: the length of the string
 */

size_t my_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * str_concat - a custom function that takes two strings, allocates
 * memory dynamically, and concatenates the tow strings into one
 *
 * @s1: the first string
 * @s2: the second string
 *
 * Return: a pointer to the concatenated string
 */

char *str_concat(char *s1, char *s2)
{
	size_t len1, len2, i;
	char *result;

	len1 = my_strlen(s1);
	len2 = my_strlen(s2);

	/* allocate memory for combined string + null terminator */
	result = malloc(len1 + len2 + 1);

	if (result == NULL)
	{
		return (NULL);
	}

	/* copy s1 into result */
	for (i = 0; i < len1; i++)
	{
		result[i] = s1[i];
	}

	/* copy s2 into result right after s1 */
	for (i = 0; i < len2; i++)
	{
		result[len1 + i] = s2[i];
	}

	/* null-terminate the result */
	result[len1 + len2] = '\0';

	return (result);
}
