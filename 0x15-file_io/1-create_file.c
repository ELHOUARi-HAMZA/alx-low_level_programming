#include<stdio.h>
#include"main.h"

/**
 * create_file- that creates text_content  terminated string to write to the file.
 *
 * Returns: 1 on success, -1 on failure.
 * 	 -1 filename is NULL.
 * 	  0 text_content, create an empty file.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, w, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(fd, text_content, len);

	if (fd == -1 || w == -1)
		return (-1);

	close(fd);

	return (1);
}
