#include "main.h"

/**
 * wildcmp - function that compares two strings and also handles the
 *           possibility of s2 having a special character *
 *
 * @s1: pointer to the first string in memory
 * @s2: pointer to the second string in memory
 *
 * Return: 1 if strings are considered identical, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	/* Base case: Both strings have reached the end */
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	/* Base Case 2: If only one string ends, they are not identical */
	if (*s1 == '\0' && *s2 != '*')
	{
		return (0);
	}

	/* wildcard case: If the current character in s2 is '*' */
	if (*s2 == '*')
	{
		/* skip '*' (empty match) or use '*' to match one or more characters in s1 */
		return (wildcmp(s1, s2 + 1) || (*s1 != '\0' && wildcmp(s1 + 1, s2)));
	}

	/* character match case: if characters match, continue with the */
	/* next character */
	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
