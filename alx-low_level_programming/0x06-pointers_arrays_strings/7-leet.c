#include "main.h"

/**
 * leet - function that encodes certain characters into numbers
 *
 * @str: pointer to the string
 *
 * Return: pointer to the modified string
 */

char *leet(char *str)
{
	char *ptr = str;

	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	while (*ptr)
	{
		int i = 0;

		while (i < 12)
		{
			if (*ptr == letters[i])
			{
				*ptr = numbers[i];
				break;
			}
			i++;
		}
		ptr++;
	}

	return (str);
}
