#include <stdio.h>
/**
 * main - Program entry point
 * description - Program that prints all the numbers of base 16 in lowercase
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char base16_number = '0';

	do {
		putchar(base16_number);
		base16_number++;
	} while (base16_number <= '9');

	base16_number = 'a';

	do {
		putchar(base16_number);
		base16_number++;
	} while (base16_number <= 'f');

	putchar('\n');

	return (0);
}
