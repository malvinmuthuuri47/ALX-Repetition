#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that uses the greedy algorithm to find the minimum
 * number of coins to make change for an amount of money
 *
 * @argc: the number of cmd arguments passed to the program
 * @argv: an array of strings storing the cmd arguments
 *
 * prints - the number of coins used to return the change
 *
 * Return: 0 on success.
 */

int main(int argc, char *argv[])
{
	int cents;
	int count, i = 0;
	int coins[5] = {25, 10, 5, 2, 1};

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	/* Loop through each coin denomination */
	for (; i < 5; i++)
	{
		while (cents >= coins[i])
		{
			cents -= coins[i];
			count++;
		}
	}

	printf("%d\n", count);
	return (0);
}
