#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>

/**
 * check_same_file - checks whether the files passed as CMD arguments
 * refer to the same file
 *
 * @source_fd: file descriptor for the source file
 * @dest_fd: file descriptor for the destination file
 *
 * Return:
 */
int check_same_file(int source_fd, int dest_fd)
{
	struct stat source_stat, dest_stat;

	if (fstat(source_fd, &source_stat) == -1)
		return (-1);

	if (fstat(dest_fd, &dest_stat) == -1)
		return (-1);

	if (
		source_stat.st_dev == dest_stat.st_dev &&
		source_stat.st_ino == dest_stat.st_ino
	)
		return (1);

	return (0);
}

int write_buffer(int dest_fd, const char *buffer, size_t bytes_to_write)
{
	ssize_t bytes_written;
	size_t total_written;

	total_written = 0;

	while (total_written < bytes_to_write)
	{
		bytes_written = write(
			dest_fd,
			buffer + total_written,
			bytes_to_write - total_written
		);

		if (bytes_written == -1)
		{
			if (errno == EINTR)
				continue;

			return (-1);
		}

		if (bytes_written == 0)
			return (-1);

		total_written += (size_t)bytes_written;
	}

	return (0);
}

int close_files(int source_fd, int dest_fd)
{
	int status;

	status = 0;

	if (close(source_fd) == -1)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't close fd %d\n",
			source_fd
		);
		status = 100;
	}

	if (close(dest_fd) == -1)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't close fd %d\n",
			dest_fd
		);
		status = 100;
	}

	return (status);
}

int open_files(
	const char *source,
	const char *dest,
	int *source_fd,
	int *dest_fd
)
{
	if (source == NULL || dest == NULL)
		return (-1);

	*source_fd = open(source, O_RDONLY);
	if (*source_fd == -1)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't read from file %s\n",
			source
		);
		return (98);
	}

	*dest_fd = open(dest, O_WRONLY | O_CREAT, 0664);
	if (*dest_fd == -1)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't write to %s\n",
			dest
		);

		if (close(*source_fd) == -1)
		{
			dprintf(
				STDERR_FILENO,
				"Error: Can't close fd %d\n",
				*source_fd
			);

			return (100);
		}
		return (99);
	}

	return (0);
}

int check_files(
	int source_fd,
	int dest_fd,
	const char *source,
	const char *dest
	)
{
	int status;

	status = check_same_file(source_fd, dest_fd);

	if (status == 98)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't read from file %s\n",
			source
		);
		return (98);
	}

	if (status == 99)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't write to %s\n",
			dest
		);
		return (99);
	}

	if (status == 1)
		return (1);

	return (0);
}

int copy_file(const char *source, const char *dest)
{
	int source_fd, dest_fd;
	int status, close_status;
	char buffer[1024];
	ssize_t bytes_read;

	status = open_files(source, dest, &source_fd, &dest_fd);
	if (status != 0)
		return (status);

	status = check_files(source_fd, dest_fd, source, dest);
	if (status == 1)
	{
		status = 0;
		goto cleanup;
	}

	if (status != 0)
		goto cleanup;

	if (ftruncate(dest_fd, 0) == -1)
	{
		dprintf(
			STDERR_FILENO,
			"Error: Can't write to %s\n",
			dest
		);
		status = 99;
		goto cleanup;
	}

	while (1)
	{
		bytes_read = read(source_fd, buffer, sizeof(buffer));

		if (bytes_read == -1)
		{
			if (errno == EINTR)
				continue;

			dprintf(
				STDERR_FILENO,
				"Error: Can't read from file %s\n",
				source
			);
			status = 98;
			goto cleanup;
		}

		if (bytes_read == 0)
			break;

		if (write_buffer(dest_fd, buffer, (size_t)bytes_read) == -1)
		{
			dprintf(
				STDERR_FILENO,
				"Error: Can't write to %s\n",
				dest
			);
			status = 99;
			goto cleanup;
		}
	}

	status = 0;

cleanup:
	close_status = close_files(source_fd, dest_fd);

	if (close_status == 100)
		status = 100;

	return (status);
}

int main(int ac, char **av)
{
	int status;

	if (ac != 3)
	{
		dprintf(
			STDERR_FILENO,
			"Usage: cp file_from file_to\n"
		);
		return (97);
	}

	status = copy_file(av[1], av[2]);

	return (status);
}
