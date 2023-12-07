#include "lists.h"

/**
* delete_dnodeint_at_index - this funct deletes a node at a specific index
* @head: represeenting double pointer
* @index: this is the index
* Return: 1 on success, else -1 on failure
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *current;
unsigned int position;

if (head == NULL || *head == NULL)
return (-1);

current = *head;

/* Check if index is out of bounds */
for (position = 0; position < index && current != NULL; position++)
current = current->next;

if (current == NULL)
return (-1); /* Index out of bounds */

if (index == 0)
{
*head = current->next;
if (current->next != NULL)
{
current->next->prev = NULL;
}
free(current);
return (1);
}

current->prev->next = current->next;
if (current->next != NULL)
current->next->prev = current->prev;
free(current);

return (1);
}
