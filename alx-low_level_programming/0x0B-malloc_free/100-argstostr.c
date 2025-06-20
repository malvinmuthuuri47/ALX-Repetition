#include "main.h"

/**
 * str_len - function that calculates the length of a string passed to it
 *
 * @str: the string
 *
 * Return: The length of the string
 */
int str_len(char *str)
{
	int len;

	len = 0;

	while (str[len] != '\0')
	{
		len++;
	}

	return (len);
}

/**
 * calculate_total_len - helper function that calculates the total length
 * needed for the dynamic memory allocation in the heap
 *
 * @ac: the number of arguments passed
 * @av: the array of the arguments stored as strings
 *
 * Return: the total space required for the string
 */
int calculate_total_len(int ac, char **av)
{
	int len, i;

	len = 0;

	for (i = 1; i < ac; i++)
	{
		len += str_len(av[i]) + 1;
	}

	return (len);
}

/**
 * copy_args_to_result - function that copies the strings passed in
 * the command line to the dynamic memory allocation
 *
 * @ac: the number of arguments passed to the command line
 * @av: the arguments stored in an array as strings
 * @result: the dynamic memory created for the final concatenated string
 *
 * Return: Nothing
 */
void copy_args_to_result(int ac, char **av, char *result)
{
	int position, i, j;
	char *arg;

	position = 0;

	for (i = 1; i < ac; i++)
	{
		j = 0;

		arg = av[i];

		/* copy each character of the argument */
		while (arg[j] != '\0')
		{
			result[position] = arg[j];
			position++;
			j++;
		}

		/* add a newline separator */
		if (i < ac)
		{
			result[position] = '\n';
			position++;
		}
	}

	/* null-terminate the final string */
	result[position] = '\0';
}

/**
 * argstostr - main function that calls the helper functions to calculate
 * the string length, create a dynamic memory, and finally concatenate
 * the strings together
 *
 * @ac: the number of arguments passed in the command line
 * @av: the strings stored in an array
 *
 * Return: a pointer to the newly created memory containing the concatenated
 * string
 */
char *argstostr(int ac, char **av)
{
	int len;
	char *result;

	len = 0;

	if (ac == 0 || av == NULL)
	{
		return (NULL);
	}

	/* calculate the total length for the final string */
	len = calculate_total_len(ac, av);

	/* allocate memory for the final concatenated string */
	result = malloc(len + 1);

	if (result == NULL)
	{
		return (NULL);
	}

	/* copy the arguments into the result string */
	copy_args_to_result(ac, av, result);

	return (result);
}
