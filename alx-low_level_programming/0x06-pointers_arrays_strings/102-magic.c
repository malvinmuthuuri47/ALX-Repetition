#include <stdio.h>

/**
 * main - function that manipulates contiguous memory allocation to access
 * other memory blocks and change the value contained there
 *
 * Return: Void
 */

int main(void)
{
	int n;
	int a[5];
	int *p;

	a[2] = 1024;
	p = &n;
	/*
	 * write your line of code here...
	 * Remember:
	 * - you are not allowed to use a
	 * - you are not allowed to modify p
	 * - only one statement
	 * - you are not allowed to code anything else than this line of code
	 */
	/* ...so that this prints 98\n */
	*(p + 5) = 98;
	printf("a[2] = %d\n", a[2]);
	return (0);
}
