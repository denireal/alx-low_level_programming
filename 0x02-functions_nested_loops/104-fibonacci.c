#include <stdio.h>

/**
 * print_fib - prints the first 50 Fibonacci numbers,
 * starting with 1 and 2, followed by a new line.
 * @len: the length up to which the Fibonacci sequence should print.
 *
 * Return: void
 */
void print_fib(int len)
{
	unsigned int target, i;
	unsigned int former_left, former_right;
	unsigned int latter_left, latter_right;
	unsigned int fib_left, fib_right;

	former_left = 1;
	former_right = 2;
	target = len - 2;

	for (i = 0; i < target; i++)
	{
		fib_left = former_left + former_right;
		printf("%d: ", i + 4);
		printf("%u", fib_left);
		former_left = former_right;
		former_right = fib_left;

		if (i < target - 1)
			printf("\n");
	}

	putchar('\n');
}

/**
 * main - Entry point.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	print_fib(98);
	return (0);
}
