#include "main.h"
#include <stdlib.h>

/**
 * array_range - Create an array of integers in a given range
 * @min: The starting value of the range (inclusive)
 * @max: The ending value of the range (inclusive)
 *
 * Return: A pointer to the dynamically allocated integer array
 * or NULL on failure
 */
int *array_range(int min, int max)
{
	int i = 0;
	int j, *a;

	if (min > max)
		return (NULL);
	j = (max - min) + 1;

	a = malloc(sizeof(int) * j);

	if (a == NULL)
		return (NULL);
	for (; i < j; i++)
	{
		a[i] = min++;
	}
	return (a);
}
