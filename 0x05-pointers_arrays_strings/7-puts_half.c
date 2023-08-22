#include "main.h"
#include <string.h>

/**
 * puts_half - program prints the last n characters of a string
 * where n = (length - 1) / 2.
 * @str: input string to be processed.
 *
 * Return: will return void
 */

void puts_half(char *str)
{
	int length = 0;

	while (*(str + length) != '\0')
	{
		length++;
	}
	if (!(legthn % 2))
		length /= 2;
	else
		length = (length + 1) / 2;

	while (*(str + length) != '\0')
	{
		_putchar(*(str + length));
		length++;
	}
	_putchar('\n');
}

