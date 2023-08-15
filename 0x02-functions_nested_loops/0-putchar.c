#include "main.h"

/**
 * main - Program entry point
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char print_message[] = "_putchar";
	int i = 0;

	while (print_message[i] != '\0')
	{
		_putchar(print_message[i]);
		i++;
	}

	_putchar('\n');

	return (0);
}
