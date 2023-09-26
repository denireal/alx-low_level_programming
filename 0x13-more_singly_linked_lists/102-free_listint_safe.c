#include "lists.h"

/**
* free_listint_safe - Frees a linked list safely.
* @h: Pointer to the pointer to the first node in the linked list.
*
* Return: Number of elements in the freed list.
*/
size_t free_listint_safe(listint_t **h)
{
size_t len = 0;
listint_t *current, *next;

if (!h || !*h)
return (0);

current = *h;

while (current)
{
next = current->next;
free(current);
current = next;
len++;
}

*h = NULL;

return (len);
}
