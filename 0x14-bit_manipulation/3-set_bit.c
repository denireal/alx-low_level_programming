#include "main.h"

/**
* set_bit - Sets a bit at a specified index to 1.
* @n: A pointer to the number in which to set the bit.
* @index: The index of the bit to be set (0-based).
*
* Return: 1 if the operation was successful, or -1 on error.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask = 1;

/* Check if index is out of bounds. */
if (index >= (sizeof(unsigned long int) * 8))
return (-1);

mask <<= index;

*n |= mask;

return (1);
}
