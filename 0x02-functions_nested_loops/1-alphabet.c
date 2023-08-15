#include "main.h"

/**
 * print_alphabet - This function prints alphabets in lowercase
 *
 * Return: void
 */

void print_alphabet(void)
{
	char lowercase_alphabet = 'a';

	for (; lowercase_alphabet <= 'z'; lowercase_alphabet++)
	{
		_putchar(lowercase_alphabet);
	}
	_putchar('\n');
}
