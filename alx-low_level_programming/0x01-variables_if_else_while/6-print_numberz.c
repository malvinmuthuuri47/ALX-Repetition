#include <stdio.h>

/**
 * main - entry point
 *
 * prints all numbers of base 10 starting from 0
 *
 * Return: always 0 on success
 */

int main(void)
{
	int a;

	for (a = 48; a <= 57; a++)
	{
		putchar(a);
	}
	putchar('\n');
	return (0);
}
