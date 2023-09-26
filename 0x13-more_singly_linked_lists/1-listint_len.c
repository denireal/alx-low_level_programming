#include "lists.h"

/**
 * listint_len - Calculates the number of elements in a linked list.
 * @h: Pointer to a linked list of type listint_t to traverse.
 *
 * Return: The count of nodes in the linked list.
 */
size_t listint_len(const listint_t *h)
{
size_t num = 0;

while (h)
{
num++;
h = h->next;
}
return (num);
}
