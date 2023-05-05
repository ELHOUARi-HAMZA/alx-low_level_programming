#include <stdio.h>
#include "main.h"

/**
 * clear_bit sets the value of a bit to 0 at a given index.
 *
 * @index: the beginning is 0.
 *
 * Returns: success 1, failure -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
