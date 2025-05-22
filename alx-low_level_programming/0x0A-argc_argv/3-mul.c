#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that performs a multiplication of cmd args
 *
 * @argc: the arguments counter
 * @argv: the argument vector that stores the args
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	if (argc < 3)
		printf("Error\n");

	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));

	return (0);
}
