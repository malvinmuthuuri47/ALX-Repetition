#include <stdio.h>

void print_number(int num)
{
	if (num < 0)
	{
		putchar('-');
		num = -num;
	}

	if (num / 10)
	{
		print_number(num / 10);
	}

	putchar((num % 10) + '0');
}

int main()
{
	print_number(12345);
	putchar('\n');
	print_number(-9876);
	putchar('\n');

	return (0);
}
