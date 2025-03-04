#include <stdio.h>

/**
 * main - Entry point
 *
 * prints the letters of the alphabet in lowercase
 *
 * Return: O on Success
 */
int main(void)
{
	int c;

	for (c = 97; c <= 122; c++)
	{
		putchar(c);
	}
	putchar('\n');
	return (0);
}
