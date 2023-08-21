#include "main.h"

/**
 * puts2 - program prints every other character of a string
 * starting with the first character.
 * @str: input string to be processed.
 *
 * Return: will return void.
 */

void puts2(char *str)
{
	int char_index = 0;

	for (; str[char_index] != '\0'; char_index++)
	{
		if (char_index % 2 == 0)
		{
			_putchar(str[char_index]);
		}
	}
	_putchar('\n');
}
