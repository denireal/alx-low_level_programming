#include "main.h"

/**
* flip_bits - Counts the number of bits needed to be flipped in n to
* become m.
* @n: The original number.
* @m: The number n would flip into.
* Return: The number of bits that need to be flipped for n to become m.
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int result = n ^ m;
	unsigned int bit_count = 0;

	for (; result > 0; result >>= 1)
	{
		if (result & 1)
			bit_count++;
	}

	return bit_count;
}
