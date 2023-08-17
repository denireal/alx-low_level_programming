#include "main.h"

/**
 * print_diagonal - prints diagonal line.
 * @n: n input integer
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int prev, i;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (i = 0 ; i < n ; i++)
	{
		prev = i;
		while (prior > 0)
		{
			_putchar(32);
			prev--;
		}
		_putchar('\\');
		_putchar('\n');
	}
}
