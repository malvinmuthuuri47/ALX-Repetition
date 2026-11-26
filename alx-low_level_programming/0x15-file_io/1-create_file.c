#include "main.h"

/**
 * create_file - function that creates a file
 *
 * @filename: name of the file to create
 * @text_content: A null terminated string to write to the file
 *
 * Return: 1 on success, -1 otherwise
 */
int create_file(const char *filename, char *text_content)
{
	ssize_t fd;
	ssize_t bytes_written;
	size_t length;

	if (filename == NULL || text_content == NULL)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	length = strlen(text_content);
	bytes_written = write(fd, text_content, length);
	if (bytes_written == -1)
	{
		close(fd);
		return (-1);
	}

	close(fd);
	return (1);
}
