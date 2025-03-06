#include "main.h"

/**
 * print_position - function to print start position in hexadecimal
 *
 * @i: the start position of the buffer
 *
 * Return: void
 */

void print_position(int i)
{
	/* print the position in hexadecimal format (8 characters) */
	printf("%08x: ", i);
}

/**
 * print_hex_content - function that prints the hexadecimal content,
 * two bytes at a time
 *
 * @b: the pointer to the buffer
 * @i: the starting position of the content in the buffer
 * @size: the size of the buffer
 *
 * Return: Void
 */

void print_hex_content(char *b, int i, int size)
{
	int j;

	/* Print the hexadecimal content, 2 bytes at a time */
	for (j = 0; j < 10; j++)
	{
		if (i + j < size)
		{
			printf("%02x", b[i + j]);
		}
		else
		{
			printf(" ");
		}
		if (j % 2 == 1)
		{
			printf(" ");
		}
	}
}

/**
 * print_ascii_content - function that prints the ascii content, so long
 * as it doesn't overflow the buffer
 *
 * @b: pointer to the buffer
 * @i: starting position of content in the buffer
 * @size: the buffer size
 *
 * Return: Void
 */

void print_ascii_content(char *b, int i, int size)
{
	int j;

	/* Print the ASCII content */
	for (j = 0; j < 10; j++)
	{
		if (i + j < size)
		{
			if (isprint(b[i + j]))
			{
				printf("%c", b[i + j]);
			}
			else
			{
				printf(".");
			}
		}
	}
}

/**
 * print_buffer - main function that prints the buffer content by combining
 * the helper functions logic above
 *
 * @b: pointer to the buffer
 * @size: buffer size
 *
 * Return: Void
 */

void print_buffer(char *b, int size)
{
	int i;

	if (size <= 0)
	{
		printf("\n");
		return;
	}

	for (i = 0; i < size; i += 10)
	{
		print_position(i);
		print_hex_content(b, i, size);
		print_ascii_content(b, i, size);
		printf("\n");
	}
}
