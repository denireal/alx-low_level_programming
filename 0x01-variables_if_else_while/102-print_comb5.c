#include <stdio.h>

/**
 * main - Program entry point
 * description - This program prints all possible combinations
 * of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int first_number, second_number;

	first_number = 0;
	while (first_number < 100)
	{
		second_number = 0;
		while (second_number < 100)
		{
			if (first_number < second_number)
			{
				putchar((first_number / 10) + 48);
				putchar((first_number % 10) + 48);
				putchar(' ');
				putchar((second_number / 10) + 48);
				putchar((second_number % 10) + 48);
				if (first_number != 98 || second_number != 99)
				{
					putchar(',');
					putchar(' ');
				}
			}
			second_number++;
		}
		first_number++;
	}
	putchar('\n');
	return (0);
}
