#include "main.h"

/**
 * print_last_digit - Program prints last digit of a given number
 * @n: The number to be checked
 *
 * Return: last_digt as the integer value
 */
int print_last_digit(int n)
{
	int last_digit;

	if (n < 0)
		last_digit = (n * -1) % 10;
	else
		last_digit = n % 10;
	_putchar(last_digit + '0');
	return (last_digit);
}
