#include "main.h"
#include <string.h>

/**
 * print_rev - program prints a string in reverse using a for loop
 * @s: string chaacter to be reversed
 *
 * Return: will return void
 */
void print_rev(char *s)
{
	int length = strlen(s);
	int index;

	for (index = length - 1; index >= 0; index--)
	{
		_putchar(s[index]);
	}
	_putchar('\n');
}
