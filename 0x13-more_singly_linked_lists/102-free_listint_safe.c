#include "lists.h"

/**
* free_listint_safe - Frees a listint_t list safely
* @h: Pointer to a pointer to the head of the list
*
* Return: (size) - The size of the list that was freed
* If the function fails, it exits with status 98
*/
size_t free_listint_safe(listint_t **h)
{
size_t size = 0;

while (*h != NULL)
{
listint_t *temp = *h;
*h = (*h)->next;
free(temp);
size++;
}

return (size);
}
