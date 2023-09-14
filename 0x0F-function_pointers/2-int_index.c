#include "3-calc.h"
#include <stddef.h>

/**
 * int_index - Searches for an integer in an array.
 * @array: Pointer to the array to search.
 * @size: Number of elements in the array.
 * @cmp: Pointer to the comparison function.
 *
 * Return: Index of the first element for which cmp returns non-zero.
 * If no element matches, return -1. If size <= 0, return -1.
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (size <= 0 || array == NULL || cmp == NULL)
		return (-1);
	for (; i < size; i++)
		if (cmp(array[i]))
			return (i);
	return (-1);
}
