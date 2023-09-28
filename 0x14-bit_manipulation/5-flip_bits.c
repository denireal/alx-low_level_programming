#include "main.h"
/**
* flip_bits - Counts the number of bits needed to flip to make n equal to m.
* @n: The first unsigned long integer.
* @m: The second unsigned long integer.
* Return: The number of flipped bits needed to make n equal to m.
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
unsigned long int xor = n ^ m;
unsigned int flips = 0;

while (xor > 0)
{
flips += xor & 1;
xor >>= 1;
}

return (flips);
}
