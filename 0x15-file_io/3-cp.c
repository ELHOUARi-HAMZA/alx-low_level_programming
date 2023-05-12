#include <stdio.h>
#include <stdlib.h>
#include "main.h"

char *create_buffer(char *file);
void close_file(int fd);

/**
 *
 * create_buffer - Allocates memory for a buffer.
 * @file: The name of the file for which the buffer is allocated.
 *
 * Return: A pointer to the newly-allocated buffer, or NULL on failure.
 *
 * Description: This function allocates memory for a buffer to store file contents.
 * The buffer size is fixed at 1024 bytes.
 * If the allocation fails, an error message is printed to stderr and the program exits with code 99.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 * Description: This function closes the specified file descriptor.
 * If the closing fails, an error message is printed to stderr and the program exits with code 100.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of command-line arguments.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success, or the appropriate exit code on failure.
 *
 * Description: This program copies the contents of one file to another file.
 * It expects two command-line arguments: the source file and the destination file.
 * If the argument count is incorrect, an error message is printed to stderr and the program exits with code 97.
 * If the source file cannot be read, an error message is printed to stderr and the program exits with code 98.
 * If the destination file cannot be created or written to, an error message is printed to stderr and the program exits with code 99.
 * If either the source file or the destination file cannot be closed, an error message is printed to stderr and the program exits with code 100.
 */
int main(int argc, char *argv[])
{
	int from, to, r, w;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		r = read(from, buffer, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r > 0);

	free(buffer);
	close_file(from);
	close_file(to);

	return (0);
}
