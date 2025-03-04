#include "main.h"

/**
 * _atoi - function that converts a string to an integer
 *
 * @s: character pointer to the string location in memory
 *
 * Return: The string as an int or 0 otherwise
 */

int _atoi(char *s)
{
	int result = 0;	/* stores the final integer value */
	int sign = 1;	/* stores the sign (Default is positive) */
	int found_num = 0;	/*  flag to check if a num has been found */

	/* Traverse the string to find the first valid sign and num */
	while (*s)
	{
		if (*s == ' ')
		{
			s++;
			continue;
		}

		/* check for sign if num has not been found yet */
		if ((*s == '+' || *s == '-') && !found_num)
		{
			sign = (*s == '-') ? -1 : 1;
		}

		/* if digit is found, start forming the num */
		else if (*s >= '0' && *s <= '9')
		{
			found_num = 1;
			result = result * 10 + (*s - '0');
		}

		/* if a non-digit is encountered after the num starts */
		else if (found_num)
		{
			break;
		}
		s++;
	}

	return (result * sign);
}
