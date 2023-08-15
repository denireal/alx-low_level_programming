#include "main.h"

/**
 * main - Program entry point
 * dedscription - Program to prints _putchar, followed by a new line
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	int i = 0;
	char print_text[] = "_putchar";

	while (print_text[i] != '\0')
	{
		_putchar(print_text[i]);
		i++;
	}

	_putchar('\n');

	return (0);
}
