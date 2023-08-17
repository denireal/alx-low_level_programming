#include "main.h"

/**
 * print_triangle - function that prints a triangle, followed by a new line.
 * Use the character # to print the triangle.
 * @size: Size of triangle
 */
void print_triangle(int size)
{
	int a = 0, i, j;

	if (size <= 0)
	{
		_putchar('\n');
		return;
	}

	for (; a < size; a++)
	{
		i = (size - 1) - a;
		j = a + 1;

		while (i > 0)
		{
			_putchar(' ');
			i--;
		}

		while (j > 0)
		{
			_putchar('#');
			j--;
		}

		_putchar('\n');
	}
}
