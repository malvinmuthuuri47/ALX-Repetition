#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 *
 * @filename: name of the file
 * @text_content: null terminated string to add at the end of file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t fd;
	size_t length;
	size_t total_written;
	ssize_t bytes_written;

	if (filename == NULL || text_content == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		length = strlen(text_content);
		total_written = 0;

		while (total_written < length)
		{
			bytes_written = write(
					fd,
					text_content + total_written,
					length - total_written
					);

			if (bytes_written == -1 || bytes_written == 0)
			{
				close(fd);
				return (-1);
			}

			total_written += (size_t)bytes_written;
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
