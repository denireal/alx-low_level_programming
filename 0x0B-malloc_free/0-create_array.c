#include "main.h"

/**
 * create_array - creates an array of characters
 * @size: the size of the array
 * @c: the character to initialize the array with
 *
 * Return: a pointer to the created array, or NULL if allocation fails
*/
char *create_array(unsigned int size, char c)
{
	unsigned int i = 0;
	char *charArray;

	if (size == 0)
		return (NULL);
	charArray = malloc(size);
	if (charArray == NULL)
		return (NULL);
	for (; i < size; i++)
	{
		charArray[i] = c;
	}
	return (charArray);
}
