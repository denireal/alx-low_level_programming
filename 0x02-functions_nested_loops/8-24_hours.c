#include "main.h"

/**
 * jack_bauer - Program prints every minute of the day
 * starting from 00:00 to 23:59.
 *
 */
void jack_bauer(void)
{
	int min = 0, hour = 0;

	for (; hour < 24; hour++)
	{
		for (; min < 60; min++)
		{
			_putchar((hour / 10) + '0');
			_putchar((hour % 10) + '0');
			_putchar(':');
			_putchar((min / 10) + '0');
			_putchar((min % 10) + '0');
			_putchar('\n');
		}
	}
}
