#include "main.h"

/**
 * string_toupper - function that converts lowercase letters in a string
 * to uppercse letters
 *
 * @str: the pointer to the string
 *
 * Return: the modified string with all lowecase letters converted to
 * uppercase letters
 */

char *string_toupper(char *str)
{
	char *ptr = str;

	while (*ptr != '\0')
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr = *ptr - ('a' - 'A');
		}
		ptr++;
	}
	return (str);
}
