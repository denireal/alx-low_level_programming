#include "main.h"

/**
 * print_array - program prints n elements of an array of integers
 * followed by a new line.
 * @a: an input array
 * @n: an input integer
 *
 * Return: will return void
 */
void print_array(int *a, int n)
{
	int i = 0;

	while (i < n)
	{
		printf("%d", a[i]);
		if (i < n - 1)
		{
			printf(", ");
		}
		i++;
	}
	putchar('\n');
}
