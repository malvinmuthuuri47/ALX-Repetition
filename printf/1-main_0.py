#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(void)
{
	int len, len2;

	len = _printf("%d", 10000);
	len2 = printf("%d", 10000);
	fflush(stdout);
	if (len != len2)
	{
		printf("Lengths differ.\n");
		fflush(stdout);
		return (1);
	}
	return (0);
}
