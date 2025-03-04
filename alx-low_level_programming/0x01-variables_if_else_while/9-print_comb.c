#include <stdio.h>

/**
 * main - entry point
 *
 * prints all possible combinations of single digit numbers
 *
 * Return: 0 on success
 */

int main(void)
{
	int a;

	for (a = 48; a <= 57; a++)
	{
		putchar(a);
		if (a < 57)
		{
			putchar(',');
			putchar(' ');
		}
	}
	putchar('\n');
	return (0);
}
