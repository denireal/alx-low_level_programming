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

	number1 = 50;
	while (number1 <= 60)
	{
		number2 = 50;
		while (number2 <= 58)
		{
			if (number2 > number1)
			{
				putchar(number1);
				putchar(number2);
				if (number1 != 60 || number2 != 58)
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
