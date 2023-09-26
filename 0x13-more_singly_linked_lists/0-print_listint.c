#include "lists.h"

/**
* count_listint - counts the number of elements in a linked list
* @h: linked list of type listint_t to count
*
* Return: number of nodes
*/
size_t count_listint(const listint_t *h)
{
size_t num = 0;

for (; h != NULL; h = h->next)
{
num++;
}

return (num);
}
