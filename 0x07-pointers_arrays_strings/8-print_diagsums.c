#include "main.h"
/**
 * print_diagsums - Calculates and prints the sum of the two diagonals
 * of a square matrix of integers.
 * @a: The matrix of integers.
 * @size: The size of the matrix.
 *
 * Return: void
 */

void print_diagsums(int *a, int size)
{
	int index = 0;
	int diag_sum1 = 0, diag_sum2 = 0;

	for (; index < size; index++)
	{
		diag_sum1 += *(a + size * index + i);
		diag_sum2 += *(a + size * (inddex + 1) - index - 1);
	}
	printf("%d, %d\n", diag_sum1, diag_sum2);
}
