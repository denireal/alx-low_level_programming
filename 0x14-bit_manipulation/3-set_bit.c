#include "main.h"

/**
* set_bit - Function to change the value of a specific bit to 1
* at the provided index.
* @n: A pointer to an unsigned long int.
* @index: The index to set the value.
*
* Return: Returns -1 if an error occurs; otherwise, returns 1.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
unsigned long int mask = 1;

if (index >= sizeof(unsigned long int) * 8)
return (-1);

mask <<= index;
*n = (*n | mask);

return (1);
}
