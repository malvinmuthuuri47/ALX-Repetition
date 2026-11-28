#include "main.h"

ssize_t copy_file(const char *source, const char *dest)
{
	ssize_t source_fd, dest_fd;
	char buffer[1024];
	ssize_t bytes_read, bytes_written;
	size_t total_written;

	if (source == NULL || dest == NULL)
		return (-1);

	source_fd = open(source, O_RDONLY);
	if (source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		return (98);
	}

	dest_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		close(source_fd);
		return (99);
	}

	while (1)
	{
		bytes_read = read(source_fd, buffer, sizeof(buffer));
		if (bytes_read == -1)
		{
			close(source_fd);
			close(dest_fd);
			dprintf(STDERR_FILENO, "Error: Failed to read from source\n");
			return (98);
		}

		if (bytes_read == 0)
			break;

		total_written = 0;

		while (total_written < (size_t)bytes_read)
		{
			bytes_written = write(
					dest_fd,
					buffer + total_written,
					(size_t)bytes_read - total_written
					);

			if (bytes_written == -1)
			{
				close(source_fd);
				close(dest_fd);
				dprintf(STDERR_FILENO, "Failed to write to dest\n");
				return (99);
			}

			if (bytes_written == 0)
			{
				close(source_fd);
				close(dest_fd);
				dprintf(STDERR_FILENO, "Write probably encoutered EOF\n");
				return (99);
			}
			
			total_written += (size_t)bytes_written;
		}
	}

	if (close(source_fd) == -1)
	{
		close(dest_fd);
		dprintf(STDERR_FILENO, "Could not close source fd\n");
		return (-1);
	}

	if (close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Could not close dest fd\n");
		close(source_fd);
		return (-1);
	}

	return (0);
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	if (copy_file(av[1], av[2]) == -1)
	{
		dprintf(STDERR_FILENO, "File Copying failed.\n");
		return (-1);
	}

	printf("File copied successfully.\n");

	return (0);
}
