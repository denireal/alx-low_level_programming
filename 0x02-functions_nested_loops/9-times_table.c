#include "main.h"

/**
 * times_table - Program prints the 9 times table
 */
void times_table(void)
{
	int num = 0, mult = 1, prod;

	for (; num < 10; num++)
	{
		_putchar('0');

		for (; mult < 10; mult++)
		{
			_putchar(',');
			_putchar(' ');

			prod = num * mult;

			if (prod < 10)
				_putchar(' ');
			else
				_putchar((prod / 10) + '0');

			_putchar((prod % 10) + '0');
		}
		_putchar('\n');
	}
}
