#include <stdio.h>
/**
 * main - Program prints first 50 Fibonacci numbers
 * starting with 1 and 2, separated by a comma followed by a space
 *
 * Return: Always 0 (Success).
 */
int main(void)
{
	int i;
	long int fib_num[50];

	fib_num[0] = 1;
	fib_num[1] = 2;
	printf("%ld, %ld, ", fib_num[0], fib_num[1]);

	for (i = 2; i < 50; i++)
	{
		fib_num[i] = fib_num[i - 1] + fib_num[i - 2];
		if (i == 49)
			printf("%ld\n", fib_num[i]);
		else
			printf("%ld, ", fib_num[i]);
	}

	return (0);
}
