#include <stdio.h>
#include "main.h"

/**
 * flip_bits sets the number of bits to flip.
 * getting one number to another.
 *
 * @n: number 1.
 * Returns: change the number's bits.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, count = 0;
	unsigned long int current;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		current = exclusive >> i;
		if (current & 1)
			count++;
	}

	return (count);
}
