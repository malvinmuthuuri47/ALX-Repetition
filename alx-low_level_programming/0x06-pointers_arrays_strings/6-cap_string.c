#include "main.h"

/**
 * *cap_string - main function to capitalize each word based
 * on specified separtors
 *
 * @str: pointer to the string location
 *
 * Return: pointer to the modified string in place
 */

char *cap_string(char *str)
{
	char *ptr = str;
	int cap_next = 1;	/* flag to check if next char should be capitalized */

	while (*ptr)
	{
		/* check if current char is a separator */
		if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n' ||
				*ptr == ',' || *ptr == ';' ||
				*ptr == '.' || *ptr == '!' ||
				*ptr == '?' || *ptr == '"' ||
				*ptr == '(' || *ptr == ')' ||
				*ptr == '{' || *ptr == '}')
		{
			cap_next = 1;
		}
		else if (cap_next && *ptr >= 'a' && *ptr <= 'z')
		{
			*ptr -= 32;
			cap_next = 0;
		}
		else
		{
			cap_next = 0;
		}
		ptr++;
	}

	return (str);
}
