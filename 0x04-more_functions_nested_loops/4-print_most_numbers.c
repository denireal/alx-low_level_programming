#include "main.h"

/**
 * print_most_numbers - prints the numbers, from 0 to 9.
 * Exclude 2 and 4.
 *
 * Return: void
 */
void print_most_numbers(void)
{
	int num = 0;

	while (num < 10)
	{
		if (num != 2 && num != 4)
			_putchar('0' + num);
		num++;
	}
	_putchar('\n');
}

