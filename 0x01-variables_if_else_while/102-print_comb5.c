#include <stdio.h>

/**
 * main - Program entry point
 * description - Program that prints all possible combinations
 * of two two-digit numbers
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int firstnum = 0, secondnum = 0;

	do {
		do {
			
			putchar((firstnum / 10) + '0');
			putchar((firstnum % 10) + '0');

			putchar(' ');

			putchar((secondnum / 10) + '0');

			putchar((secondnum % 10) + '0');

			if (firstnum != 99 || secondnum != 99)
			{
				putchar(',');
				putchar(' ');
			}

			secondnum++;

			if (secondnum == 100)
			{
				secondnum = 0;
				firstnum++;
			}
		} while (firstnum < 100);
		firstnum = 0;
	} while (secondnum < 100);

	return (0);
}
