#include <stdlib.h>
#include "lists.h"

/**
* delete_dnodeint_at_index - Deletes a node at a specific index
* @head: Double pointer to the linked list
* @index: Index at which to delete node
* Return: 1 on success, -1 on failure
*/
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *deleted_node;

if (!head || !*head)
return (-1);

deleted_node = get_dnodeint_at_index(*head, index);
if (!deleted_node)
return (-1);

if (deleted_node->prev)
deleted_node->prev->next = deleted_node->next;
else
*head = deleted_node->next;

if (deleted_node->next)
deleted_node->next->prev = deleted_node->prev;

free(deleted_node);

return (1);
}

/**
* get_dnodeint_at_index - Gets the node at a given index
* @head: Pointer to the head of the list
* @index: Index of the desired node
* Return: Node at the specified index, or NULL if not found
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int current;

for (current = 0; head && current < index; current++)
head = head->next;

return (head);
}
