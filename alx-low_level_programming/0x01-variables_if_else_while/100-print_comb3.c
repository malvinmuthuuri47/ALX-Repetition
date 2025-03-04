#include <stdio.h>

/**
 * main - entry point
 *
 * prints all possible different combinations of two digits
 *
 * Return: 0 on success
 */

int main(void)
{
	int a;
	int b;
	int is_last = 0;

	for (a = 48; a <= 57; a++)
	{
		for (b = 48; b <= 57; b++)
		{
			if (a != b && a < b)
			{
				if (is_last)
				{
					putchar(',');
					putchar(' ');
				}
				putchar(a);
				putchar(b);
				is_last = 1;
			}
		}
	}
	putchar('\n');
	return (0);
}
