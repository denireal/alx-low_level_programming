#include "main.h"
/**
 * print_sign - Program prints sign of a given number + or -
 * @n: Number to be checked
 *
 * Return: Return 1 if +ve and > 0. Return 0 if -ve
 */
int print_sign(int n)
{
	if (n > 0)
	{
		_putchar('+');
		return (1);
	}
	else if (n == 0)
	{
		_putchar('0');
		return (0);
	}
	else
	{
		_putchar('-');
		return (-1);
	}
}

