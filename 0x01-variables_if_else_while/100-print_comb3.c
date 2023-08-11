#include <stdio.h>

/**
 * main - Program entry point
 * description - Program that prints all possible
 * different combinations of two digits
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int number1, number2;

	number1 = 48;
	while (number1 <= 57)
	{
		number2 = 48;
		while (number2 <= 57)
		{
			if (number2 > number1)
			{
				putchar(number1);
				putchar(number2);
				if (number1 != 56 || number2 != 57)
				{
					putchar(',');
					putchar(' ');
				}
			}
			number2++;
		}
		number1++;
	}
	putchar('\n');
	return (0);
}
