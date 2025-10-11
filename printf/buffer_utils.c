#include "main.h"
/**
 * flush_buffer - function that clears content stored in the buffer
 *
 * @buffer: pointer to the buffer in memory
 * @idx: pointer to indexes in the buffer
 *
 * Return: None
 */
void flush_buffer(char *buffer, int *idx)
{
	if (*idx > 0)
	{
		write(1, buffer, *idx);
		*idx = 0;
	}
}

/**
 * buffer_putchar - function that writes a single character into the buffer
 *
 * @c: the character to be written that is pointed to by idx
 * @buffer: the storage location where the characters are to be written
 * @idx: the index to iterate the buffer using
 * @buf_size: the size of the buffer
 * @total: the total number of characters written in the buffer
 *
 * Return: None
 */
void buffer_putchar(char c, char *buffer,
		int *idx, int buf_size, int *total)
{
	if (*idx >= buf_size)
		flush_buffer(buffer, idx);

	buffer[(*idx)++] = c;
	(*total)++;
}

/**
 * buffer_puts - a function that writes multiple characters (strings)
 * into the buffer
 *
 * @s: pointer to the string to be written in the buffer
 * @buffer: the locaiton in memory the string will be stored
 * @idx: an iterator to be used to iterate through the buffer
 * @buf_size: the size of the buffer
 * @total: the total no. of characters written in the buffer
 *
 * Return: void
 */
void buffer_puts(const char *s, char *buffer,
		int *idx, int buf_size, int *total)
{
	while (*s)
	{
		if (*idx > buf_size)
			flush_buffer(buffer, idx);

		buffer[(*idx)++] = *s++;
		(*total)++;
	}
}
