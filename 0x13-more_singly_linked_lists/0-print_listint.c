#include "lists.h"

/**
* count_listint - counts the number of elements in a linked list
* @h: linked list of type listint_t to count
*
* Return: number of nodes
*/
size_t count_listint(const listint_t *h)
{
size_t new_nodes = 0;

while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
new_nodes++;
}
return (new_nodes);
}
