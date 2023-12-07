#include "lists.h"

/**
* get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list
* @head: Pointer to the head of the list
* @index: Index of the node to retrieve (starting from 0)
* Return: Pointer to the nth node, or NULL if the node does not exist
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int i = 0;
dlistint_t *current = head;

while (current != NULL && i < index)
{
current = current->next;
i++;
}

return (current);
}
