#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * _calloc - Allocate memory for an array of elements
 * and initialize to zero
 * @nmemb: The number of elements
 * @size: The size (in bytes) of each element
 *
 * Return: A pointer to the allocated and initialized memory
 * or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	memset(ptr, 0, nmemb * size);

	return (ptr);
}
