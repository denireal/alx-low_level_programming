#include "lists.h"

/**
* delete_nodeint_at_index - Deletes a node in a linked list at a specified index.
* @head: Pointer to the pointer to the first element in the list.
* @index: The index of the node to delete.
*
* Return: 1 on success, or -1 on failure.
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
unsigned int i;
listint_t *prev;
listint_t *next;

prev = *head;

if (index != 0)
{
for (i = 0; i < index - 1 && prev != NULL; i++)
{
prev = prev->next;
}
}

if (prev == NULL || (prev->next == NULL && index != 0))
{
return (-1);
}

next = prev->next;

if (index != 0)
{
prev->next = next->next;
free(next);
}
else
{
free(prev);
*head = next;
}

return (1);
}
