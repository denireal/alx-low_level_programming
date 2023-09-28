#include "main.h"

/**
* clear_bit - Sets a specific bit at the given index to 0.
*
* This function modifies a bit at a specific index within
* an unsigned long
* integer by setting it to 0.
*
* @n: A pointer to the unsigned long integer to modify.
* @index: The index at which to clear the bit.
*
* Return: 1 if the operation was successful, or -1 on error.
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= sizeof(unsigned long int) * 8)
return (-1);

*n &= ~(1UL << index);
return (1);
}
