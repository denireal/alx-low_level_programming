#include "main.h"

/**
* clear_bit - Sets the value of a bit to 0 at a given index.
* @n: A pointer to an unsigned long integer.
* @index: The index to set the value.
* Return: Return -1 if an error occurs; otherwise, return 1.
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
if (index >= (sizeof(unsigned long int) * 8))
return (-1);

*n &= ~(1UL << index);

return (1);
}
