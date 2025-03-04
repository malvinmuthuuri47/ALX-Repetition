#include <stdio.h>

/**
 * main - entry point
 *
 * prints all possible different combinations of three digits
 *
 * Return: 0 on success
 */

int main(void)
{
	int a;
	int b;
	int c;
	int is_last = 0;

	for (a = 48; a <= 57; a++)
	{
		for (b = 48; b <= 57; b++)
		{
			for (c = 48; c <= 57; c++)
			{
				if (a != b && b != c && a != c && a < b && b < c && a < c)
				{
					if (is_last)
					{
						putchar(',');
						putchar(' ');
					}
					putchar(a);
					putchar(b);
					putchar(c);
					is_last = 1;
				}
			}
		}
	}
	putchar('\n');
	return (0);
}
