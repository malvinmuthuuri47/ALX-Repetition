#include "main.h"

/**
 * swap_int - main function that swaps the values held by pointers
 *
 * @a: first pointer pointing to a memory address
 * @b: second pointer pointing to a memory address
 */

void swap_int(int *a, int *b)
{
	int c = 0;

	c = *a;
	*a = *b;
	*b = c;
}
