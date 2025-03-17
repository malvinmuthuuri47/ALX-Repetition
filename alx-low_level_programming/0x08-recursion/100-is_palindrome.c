#include "main.h"

/**
 * str_length - helper function that calculates the length of a string
 *
 * @str: pointer to the string in memory
 *
 * Return: the length of the string, 0 otherwise
 */

int str_length(const char *str)
{
	int len;

	len = 0;

	if (!str)
	{
		return (0);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * is_palindrome_helper - helper function that checks if a string is a
 *                        palindrome recursively
 *
 * @str: pointer to the string in memory
 * @start: the start index of the string
 * @end: the end index of the string
 *
 * Return: 1 if string is a palindrome, 0 otherwise
 */

int is_palindrome_helper(const char *str, int start, int end)
{
	if (start >= end)
	{
		/* Base case: single char or empty substring is a palindrome */
		return (1);
	}
	if (str[start] != str[end])
	{
		/* Base case: mismatch found, not a palindrome */
		return (0);
	}
	return (is_palindrome_helper(str, start + 1, end - 1));
}

/**
 * is_palindrome - main function that combines the helper functions to find
 *                 the string length and check if the string is a palindrome
 *
 * @s: the pointer to the string in memory
 *
 * Return: the return value of is_palindrome_helper
 */

int is_palindrome(char *s)
{
	int len;

	if (!s)
	{
		return (0);
	}
	len = str_length(s);
	return (is_palindrome_helper(s, 0, len - 1));
}
