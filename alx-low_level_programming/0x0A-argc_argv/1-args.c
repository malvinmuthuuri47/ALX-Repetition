#include "main.h"

/**
 * main - function that prints the number of arguments passed to it
 *
 * @argc: argument counter
 * @argv: array of string arguments passed in the command line
 *
 * Return: 0
 */

int main(int argc, char *argv[] __attribute__((unused)))
{
	printf("%d\n", argc - 1);
	return (0);
}
