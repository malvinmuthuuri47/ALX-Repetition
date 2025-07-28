#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - function that takes command line arguments to perform arithmetic
 * operations on the command line arguments passed to it.
 *
 * @argc: the number of arguments passed to the function
 * @argv: an argument vector that stores the cmd args with their index
 * for later use in the program
 *
 * Return: An integer based on the result of the arithmetic operations and
 * whether the program conditions have been met.
 *
 * The conditions are:
 * the no. of arguments passed are equal to 4
 * the arithmetic operations from the command line are valid
 * the numbers passed are valid in mathematical calculations
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	int (*operation)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);
	operation = get_op_func(argv[2]);

	if (operation == NULL)
	{
		printf("Error\n");
		exit(99);
	}

	if ((argv[2][0] == '/' || argv[2][0] == '%') && num2 == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = operation(num1, num2);
	printf("%d\n", result);
	return (0);
}
