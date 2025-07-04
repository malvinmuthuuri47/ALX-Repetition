#include "main.h"

/**
 * is_null_char - function that checks if the current character is a \
 * null terminator
 *
 * @c: the character
 *
 * Return: 1 if true, 0 otherwise
 */
int is_null_char(char c)
{
	return (c == '\0');
}

/**
 * str_len - function that calculates the length of a string passed to it
 *
 * @str: the string
 *
 * Return: 0 if no string is passed, or the total length
 */
int str_len(char *str)
{
	int len;

	len = 0;

	if (!str)
		return (0);

	while (!is_null_char(str[len]))
		len++;

	return (len);
}

/**
 * string_nconcat - function that concatenates string one with bytes specified
 * by the third function parameter
 *
 * @s1: the first string
 * @s2: the second string
 * @n: the bytes that determine the length of string two to copy
 *
 * Return: pointer to the newly concatenated string
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1, len2, copy_len, total_len, i, j;
	char *result;

	len1 = str_len(s1);
	len2 = str_len(s2);
	if (n >= len2)
		copy_len = len2;
	else
		copy_len = n;
	total_len = len1 + copy_len;
	result = malloc(total_len + 1);

	if (!result)
		return (NULL);

	/* copy s1 */
	for (i = 0; i < len1; i++)
		result[i] = s1[i];

	/* copy up to n chars from s2 */
	for (j = 0; j < copy_len; j++)
		result[i + j] = s2[j];

	result[total_len] = '\0';

	return (result);
}
