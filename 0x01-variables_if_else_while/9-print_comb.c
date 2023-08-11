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
	unsigned int number = 48;

	while (number <= 57)
	{
		putchar(number);
		if (number != 57)
		{
			putchar(',');
			putchar(' ');
		}
		number++;
	}
	putchar('\n');
	return (0);
}
