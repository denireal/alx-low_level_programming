#include "main.h"

/**
 * print_square - program print a square given a particular size
 * followed by a new line
 * @size: the input
 */

void print_square(int size)
{
	int a, b;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (a = size ; a > 0 ; a--)
	{
		for (b = size ; b > 0 ; b--)
		{
			_putchar('#');
		}
		_putchar('\n');
	}
}
