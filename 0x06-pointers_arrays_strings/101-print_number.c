#include "main.h"

/**
* print_number - program prints an integer.
* @n: The integer variable
*
* Return: returns void
*/

void print_number(int n)
{
	unsigned int a = n;

	if (n < 0)
	{
		_putchar('-');
		a = -a;
	}

	if ((a / 10) > 0)
		print_number(a / 10);

	_putchar((a % 10) + '0');
}
