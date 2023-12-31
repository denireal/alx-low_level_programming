#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
* list_len - returns the number of elements in a linked list
* @h: pointer to the list_t list
*
* Return: number of elements in h
*/
size_t list_len(const list_t *h)
{
	size_t n = 0;

	if (h == NULL)
		return (0);

	do {
		n++;
		h = h->next;
	} while (h != NULL);

	return (n);
}
