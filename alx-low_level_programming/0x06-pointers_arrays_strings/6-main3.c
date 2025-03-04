#include <stdio.h>

char *cap_string(char *);

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char s[] = "";
	char *p;

	p = cap_string(s);
	printf("%s\n", p);
	printf("%s\n", s);
	return (0);
}
