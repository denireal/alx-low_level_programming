#include "main.h"

/**
 **_puts - program uses a for loop to print
 *a string
 *@str: pointer variable to be printed.
 *
 *Return: will return void.
 */
void _puts(char *str)
{
	int ptr;

	for (ptr = 0; str[ptr] != '\0'; ptr++)
	{
		_putchar(str[ptr]);
	}
	_putchar('\n');
}
