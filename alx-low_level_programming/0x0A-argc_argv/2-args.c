#include <stdio.h>

/**
 * main - function that prints all the arguments it receives from cmd
 *
 * @argc: the count to the number of arguments received
 * @argv: an array of strings containing the arguments
 *
 * Return: Always 0
 */

int main(int argc, char *argv[])
{
	/* loop through all arguments and print each one */
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}

	return (0);
}
