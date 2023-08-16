#include <stdio.h>

/**
 * print_fibonacci - Program prints the first 50 Fibonacci numbers,
 * description - Starts with 1 and 2, followed by a new line.
 * @length: The length up to which the Fibonacci sequence should print.
 *
 * Return: void
 */
void print_fibonacci(int length)
{
	unsigned int set_point, i;
	unsigned int prev_left, prev_right;
	unsigned int curr_left, curr_right;
	unsigned int next_left, next_right;

	prev_left = 1;
	prev_right = 2;
	set_point = length - 2;

	for (i = 0; i < set_point; i++)
	{
		next_left = prev_left + prev_right;
		printf("%d: ", i + 4);
		printf("%u", next_left);
		prev_left = prev_right;
		prev_right = next_left;

		if (i < set_point - 1)
			printf("\n");
	}
	putchar('\n');
}

/**
 * main - Program entry point.
 *
 * Return: Always 0 (success).
 */
int main(void)
{
	print_fibonacci(98);
	return (0);
}
