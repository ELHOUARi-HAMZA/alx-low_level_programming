#include "main.h"
#include <unistd.h>

/**
 * _putchar writes all the characters c to stdout
 * @c: print the character
 *
 * Return: On success, returns 1.
 * On error, returns -1 and sets errno appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
