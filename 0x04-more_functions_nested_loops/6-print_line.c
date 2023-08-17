#include "main.h"

/**
 * print_line - program draws a straight line in the terminal.
 * @line: the integer to be inputed
 *
 * Return: void
 */
void print_line(int line)
{
	int i = 0;

	if (line > 0)
	{
		while (i < line)
		{
			_putchar('_');
			i++;
		}
	}
	_putchar('\n');
}
