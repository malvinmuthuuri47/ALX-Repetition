#include <stdio.h>

/**
 * main - entry point
 *
 * prints all single digit nums of base 10 starting from o
 *
 * Return: 0 on success
 */

int main(void)
{
	int a;

	for (a = 0; a <= 9; a++)
	{
		printf("%d", a);
	}
	putchar('\n');
	return (0);

}
