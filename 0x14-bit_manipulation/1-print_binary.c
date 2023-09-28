#include "main.h"

/**
* print_binary - Outputs the binary representation of a given number.
* @n: The number for which the binary representation will be displayed.
*/
void print_binary(unsigned long int n)
{
if (n == 0)
{
_putchar('0');  /* Display '0' for the special case when n is zero. */
return;         /* Terminate the function. */
}

if (n > 1)
print_binary(n >> 1);

_putchar((n & 1) + '0');
}
