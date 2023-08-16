#include <stdio.h>

/**
 * main - Program entry point
 * description - Prints the sum of the even-valued terms
 * followed by a new line
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int i;
	long int fib_num[50], sum = 2;

	fib_num[0] = 1;
	fib_num[1] = 2;

	for (i = 2; i < 50; i++)
	{
		fib_num[i] = fib_num[i - 1] + fib_num[i - 2];
		if ((fib_num[i] % 2) == 0 && fib_num[i] < 4000000)
			sum += fib_num[i];
	}
	printf("%ld\n", sum);

	return (0);
}
