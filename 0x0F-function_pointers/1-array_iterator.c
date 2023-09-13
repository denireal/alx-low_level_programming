#include "function_pointers.h"

/**
 * array_iterator - apply an action to each element of an integer array. * @array: pointer to the integer array.
 * @size: size of the array.
 * @action: pointer to function that takes an integer as an argument.    */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t ct = 0;

	if (array == NULL || action == NULL)
	{
		return;
	}
	for (; ct < size; ct++)
	{
		action(array[ct]);
	}
}
