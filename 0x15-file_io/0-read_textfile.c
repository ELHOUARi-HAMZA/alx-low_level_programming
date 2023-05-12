#include"main.h"
#include<stdlib.h>

/**
 *read_textfile- reads a text file also prints it to POSIX standard output.
 *
 *return:the actual number of letters it could read and print.
 *	0 when filename is NULL && write fails or does not write the expected amount of bytes.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t fd;
	ssize_t w;
	ssize_t t;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	t = read(fd, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	free(buf);
	close(fd);
	return (w);
}
