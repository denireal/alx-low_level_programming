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
	int i, length = strlen(str);
	int start_index;

	if (length % 2 == 0)
	{
		start_index = length / 2;
	}
	else
	{
		start_index = (length - 1) / 2;
	}

	for (i = start_index; i < length; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
