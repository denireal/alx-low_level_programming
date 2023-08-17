#include "main.h"

/**
 * more_numbers - program prints numbers 0 to 14, 10x
 *
 * Return: void
 */
void more_numbers(void)
{
	int i = 0;
	int num = 0;

	for ( ; i < 10 ; i++)
	{
		while (num < 15)
		{
			if (num > 9)
				_putchar('0' + num / 10);
			_putchar('0' + num % 10);
			num++;
		}
		num = 0;
		_putchar('\n');
	}
}

