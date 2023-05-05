#include <stdio.h>
#include <stdio.h>

/**
 * sets git, giving it 1.
 * @n: the changing pointer.
 *
 * Returns: success 1, failure -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = ((1UL << index) | *n);
	return (1);
}
