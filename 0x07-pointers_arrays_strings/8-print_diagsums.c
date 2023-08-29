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
	int main_diag_sum = 0;
	int secondary_diag_sum = 0;
	int row;

	for (row = 0; row < size; row++)
	{
		main_diag_sum += *(a + row * size + row);
		secondary_diag_sum += *(a + row * size + (size - 1 - row));
	}
	printf("%d, %d\n", main_diag_sum, secondary_diag_sum);
}
