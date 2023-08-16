#include <stdio.h>

/**
 * main - Program entry point
 * description - Computes & prints the sum of all the multiples
 * of 3 or 5 below 1024 (excluded), followed by a new line.
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int count = 0, sum = 0;

	for (; count < 1024; count++)
	{
		if ((count % 3) == 0 || (count % 5) == 0)
			sum = sum + count;
	}

	printf("%d\n", sum);

	return (0);
}
