#include <stdio.h>
/**
 * main - Program prints first 50 Fibonacci numbers
 * starting with 1 and 2, separated by a comma followed by a space
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int fib_num[50];

	fib_num[0] = 1;
	fib_num[1] = 2;

	int i = 2;

	while (i < 50)
	{
		fib_num[i] = fib_num[i - 1] + fib_num[i - 2];
		i++;
	}

	i = 0;

	while (i < 49)
	{
		printf("%d, ", fib_num[i]);
		i++;
	}
	printf("%d\n", fib_num[49]);

	return (0);
}
