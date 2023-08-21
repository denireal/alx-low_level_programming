#include "main.h"

/**
 * swap_int - program swaps an int value to 98.
 * @x: one of the variables to be swaped
 * @y: two of the variables to be swapped
 */
void swap_int(int *x, int *y)
{
	int tmp;

	tmp = *x;

	*x = *y;
	*y = tmp;
}
