#include "main.h"
/**
 * _puts_recursion - function displays a string followed by a newline using recursion
 * @s: pointer to the string to be printed
 *
 * Return: will return void
 */
void _puts_recursion(char *s)
{
	if (*s != '\0')
	{
		_putchar(*s);
		_puts_recursion(s + 1);
	}
	else
	{
		_putchar('\n');
	}
}
