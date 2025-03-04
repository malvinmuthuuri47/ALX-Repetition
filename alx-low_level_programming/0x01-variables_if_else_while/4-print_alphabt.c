#include <stdio.h>

/**
 * main - Entry point
 *
 * prints all lowercase aphabets except q and e
 *
 * Return: 0 on success
 */

int main(void)
{
	int c;

	for (c = 97; c <= 122; c++)
	{
		if (!((c == 101) || (c == 113)))
		{
			putchar(c);
		};
	};
	putchar('\n');
	return (0);
}
