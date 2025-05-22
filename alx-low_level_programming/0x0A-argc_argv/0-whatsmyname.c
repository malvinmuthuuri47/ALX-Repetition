#include "main.h"

/**
 * main - function that prints the name of the running program
 *
 * @argc: argument counter for args passed in the command line
 * @argv: array of strings passed in the command line to the function
 *
 * Return: 0.
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	int i;

	i = 0;
	printf("%s\n", argv[i]);
	return (0);
}

