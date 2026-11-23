#include "main.h"

/**
 * get_endianness - checks the byte order in memory
 *
 * Return: 1 if little Endian, 0 if Big Endian
 */
int get_endianness(void)
{
	unsigned int num;
	unsigned char *ptr;

	num = 1;
	ptr = (unsigned char *)&num;

	if (*ptr == 1)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
