#include "main.h"
#include <stdlib.h>
#include <string.h>
/**
 * _realloc - Reallocates a memory block.
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space of ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: Pointer to the reallocated memory block.
 * return ptr without changes if new_size is equal to old_size
 * return null if malloc fails or new_size is 0.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
	{
		ptr = malloc(new_size);
		if (ptr == NULL)
		{
			return (NULL);
		}
	}
	else if (new_size != old_size)
	{
		void *new_ptr = malloc(new_size);

		if (new_ptr == NULL)
		{
			return (NULL);
		}
		if (new_size > old_size)
		{
			emcpy(new_ptr, ptr, old_size);
		}
		else
		{
			memcpy(new_ptr, ptr, new_size);
		}
		ree(ptr);
		ptr = new_ptr;
	}
	return (ptr);
}
