#include "main.h"

/**
 * print_array - main code to print the elements of the array based
 * on the number specified
 *
 * @a: The pointer to the array address in memory
 * @n: The size/number of array elements to print
 *
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i != (n - 1))
		{
			printf(", ");
		}
	}
	printf("\n");
}
