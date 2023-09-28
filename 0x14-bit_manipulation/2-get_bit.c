#include "main.h"

/**
* get_bit - Retrieves a bit at a specified index.
* @n: The number from which to extract the bit.
* @index: The index of the bit to be retrieved (0-based).
*
* Return: The value of the bit at the given index,
* or -1 if an error occurs.
*/
int get_bit(unsigned long int n, unsigned int index)
{
unsigned long int mask = 1;

if (index >= (sizeof(unsigned long int) * 8))
return (-1);

mask <<= index;

if ((n & mask))
return (1);  /* The bit is 1. */
else
return (0);  /* The bit is 0. */
}
