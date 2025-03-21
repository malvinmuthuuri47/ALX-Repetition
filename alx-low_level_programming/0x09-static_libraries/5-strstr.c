#include "main.h"

/**
 * _strstr - function that finds the first occurrence of substring
 *           needle in the string
 *
 * @haystack: pointer to the string
 * @needle: pointer to the substring to check
 *
 * Return: pointer to the beginning of the located substring,
 *         NULL otherwise
 */

char *_strstr(char *haystack, char *needle)
{
	char *h, *n;

	/* if needle is empty, return `haystack` */
	if (*needle == '\0')
	{
		return (haystack);
	}

	while (*haystack)
	{
		h = haystack;
		n = needle;

		/* Compare characters of `haystack` and `needle` */
		while (*h && *n && (*h == *n))
		{
			h++;
			n++;
		}

		/* If we reached the end of `needle`, a match was found */
		if (*n == '\0')
		{
			return (haystack);
		}
		haystack++; /* Move to the next char in `haystack` */
	}

	return (NULL);
}
