#include <stdio.h>

/**
 * main - Entry point
 *
 * prints the alphabet in lowercase and then uppercase
 *
 * Return: 0 on success
 */

int main(void)
{
	int c;

	for (c = 97; c <= 122; c++)
	{
		putchar(c);
	};
	for (c = 65; c <= 90; c++)
	{
		putchar(c);
	}
	putchar('\n');
	return (0);
}
