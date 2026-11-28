#include "main.h"

/**
 * open_files - function that opens and performs file identity checks
 *
 * @source: pathname of file whose content is to be copied
 * @dest: pathname of file to receive the content
 * @source_fd: ptr to variable that will store source file file descriptor
 * @dest_fd: ptr to variable that will store dest file file descriptor
 *
 * Return: 0 if source and dest files are different, 98 and 99 if source
 * and dest files comparison results in an error, and 1 if both files are
 * the same
 */
int open_files(
	const char *source, const char *dest, int *source_fd, int *dest_fd)
{
	struct stat source_stat, dest_stat;

	*source_fd = -1;
	*dest_fd = -1;

	if (source == NULL || dest == NULL)
		return (-1);

	*source_fd = open(source, O_RDONLY);
	if (*source_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);
		return (98);
	}

	*dest_fd = open(dest, O_WRONLY | O_CREAT, 0664);
	if (*dest_fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
		if (close(*source_fd) == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", *source_fd);
			return (100);
		}
		return (99);
	}

	if (fstat(*source_fd, &source_stat) == -1)
		return (98);

	if (fstat(*dest_fd, &dest_stat) == -1)
		return (99);

	if (source_stat.st_dev == dest_stat.st_dev &&
		source_stat.st_ino == dest_stat.st_ino)
		return (1);

	return (0);
}

/**
 * copy_contents - function that reads and writes file content from
 * source file to dest file
 *
 * @source_fd: file descriptor representing source file to read from
 * @dest_fd: file descriptor representing source file to write to
 *
 * Return: 99 if can't read from src file, 99 if can't write to
 * dest file, 0 otherwise
 */
int copy_contents(int source_fd, int dest_fd)
{
	char buffer[1024];
	ssize_t bytes_read, bytes_written;
	size_t total_written;

	while (1)
	{
		bytes_read = read(source_fd, buffer, sizeof(buffer));

		if (bytes_read == -1)
		{
			if (errno == EINTR)
				continue;
			return (98);
		}

		if (bytes_read == 0)
			break;

		while (total_written < (size_t)bytes_read)
		{
			bytes_written = write(
				dest_fd,
				buffer + total_written,
				(size_t)bytes_read - total_written
			);
			if (bytes_written == -1)
			{
				if (errno == EINTR)
					continue;
				return (99);
			}
			if (bytes_written == 0)
				return (99);
			total_written += (size_t)bytes_written;
		}
	}

	return (0);
}

/**
 * close_files - function that closes the files pointed to by src
 * and dest file descriptors
 *
 * @source_fd: file descriptor to the src file
 * @dest_fd: file descriptor to the destination file
 *
 * Return: 100 if src and dest fd encounter an error when being closed,
 * 0 otherwise
 */
int close_files(int source_fd, int dest_fd)
{
	int status;

	status = 0;

	if (source_fd != -1 && close(source_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", source_fd);
		status = 100;
	}

	if (dest_fd != -1 && close(dest_fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
		status = 100;
	}

	return (status);
}

/**
 * copy_file - Calls the helpers above to copy content from src to dest
 *
 * @source: Pathname to the src file to copy from
 * @dest: Pathname to the dest file to copy to
 *
 * Return: a status code depending on how the helper function operations
 * go
 */
int copy_file(const char *source, const char *dest)
{
	int source_fd, dest_fd;
	int status, close_status;

	status = open_files(source, dest, &source_fd, &dest_fd);

	if (status == 0)
	{
		if (ftruncate(dest_fd, 0) == -1)
			status = 99;
		else
			status = copy_contents(source_fd, dest_fd);
	}
	else if (status == 1)
		status = 0;

	close_status = close_files(source_fd, dest_fd);

	if (close_status == 100)
		status = 100;

	if (status == 98)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", source);

	if (status == 99)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);

	return (status);
}

/**
 * main - main function
 *
 * @ac: argument count for number of arguments passed when running script
 * @av: an array that stores a reference to the arguments passed by idx
 *
 * Return: The resulting return value of copy_file function
 */
int main(int ac, char **av)
{
	int status;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	status = copy_file(av[1], av[2]);

	return (status);
}
