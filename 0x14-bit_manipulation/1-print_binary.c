#include "main.h"

/**
 * print_binary - Displays the binary representation of a given number.
 * @n: The number to be shown in binary format.
 */

void print_binary(unsigned long int n)
{
int shift;
int bit_flag = 0;

if (n == 0)
{
_putchar('0');
return;
}

shift = sizeof(n) * 8 - 1;
while (shift >= 0)
{
bit_flag = (n >> shift) & 1;
if (bit_flag)
_putchar('1');
else if (bit_flag == 0)
_putchar('0');
shift--;
}
}
