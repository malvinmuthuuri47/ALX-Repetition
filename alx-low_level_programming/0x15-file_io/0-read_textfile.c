#include "main.h"

/**
 * write_buffer - helper function that writes to the buffer the
 * bytes passed to it
 *
 * @buffer: buffer to be used to write to file descriptor
 * @bytes_to_write: bytes to be written
 *
 * Return: total bytes written, -1 otherwise
 */
ssize_t write_buffer(const char *buffer, size_t bytes_to_write)
{
	ssize_t bytes_written;
	size_t total_written;

	total_written = 0;
	while (total_written < bytes_to_write)
	{
		bytes_written = write(
				STDOUT_FILENO,
				buffer + total_written,
				bytes_to_write - total_written
				);

		if (bytes_written <= 0)
			return (-1);

		total_written += bytes_written;
	}

	return ((ssize_t)total_written);
}

/**
 * read_textfile - function that reads a text file and prints it
 * to the POSIX standard output
 *
 * @filename: pointer to the file location
 * @letters: number of letters to be read from the file
 *
 * Return: Actual number of letters that were read, 0 otherwise
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t bytes_read;
	ssize_t bytes_written;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(letters) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	bytes_read = read(fd, buffer, letters);
	if (bytes_read <= 0)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	bytes_written = write_buffer(buffer, (size_t)bytes_read);

	if (bytes_written == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}

	free(buffer);
	close(fd);

	return (bytes_written);
}
