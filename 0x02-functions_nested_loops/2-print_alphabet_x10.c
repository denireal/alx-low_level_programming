#include "main.h"

/**
 * print_alphabet_x10 - This program prints alphabets
 * in lowercase 10 times
 *
 * Return: void
 */
void print_alphabet_x10(void)
{
	int count;
	char lowercase_alpha;

	for (count = 0; count <= 9; count++)
	{
		lowercase_alpha = 'a';

		for (; lowercase_alpha <= 'z'; lowercase_alpha++)
		{
			_putchar(lowercase_alpha);
		}
		_putchar('\n');
	}
}
