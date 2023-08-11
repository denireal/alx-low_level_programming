#include <stdio.h>

/**
 * main - Program entry point
 * description - Program that prints all possible combinations
 * of single-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int single_digit_numbers = 0;

	do {
		putchar(single_digit_numbers + '0');

		if (single_digit_numbers != 19)
		{
			putchar(',');
			putchar(' ');
		}

		single_digit_numbers++;

	} while (single_digit_numbers <= 9);

	return (0);
}
