#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/**
 * is_valid_num - helper func that checks if a num is a valid num
 *
 * @str: a string to iterate through to check if num is valid
 *
 * Return: 1 if invalid, 0 otherwise
 */

int is_valid_num(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
		{
			return (1);
		}
	}

	return (0);
}


/**
 * main - main function to print the sum of cmd args based on user input
 *
 * @argc: the argument count
 * @argv: the argument vector containing the command line args
 *
 * Return: 0 on success, 1 otherwise
 */

int main(int argc, char *argv[])
{
	int sum, i;

	if (argc < 2)
	{
		printf("%d\n", 0);
		return (1);
	}


	/* Loop through all provided arguments */
	for (i = 1; i < argc; i++)
	{
		if (is_valid_num(argv[i]))
		{
			printf("Error\n");
			return (1);
		}

		sum += atoi(argv[i]);
	}

	printf("%d\n", sum);

	return (0);
}
