#include <stdlib.h>
#include "lists.h"

/**
* get_dnodeint_at_index - Gets the node at a given index
* @head: Pointer to the head of the list
* @index: Index of the desired node
* Return: Node at the specified index, or NULL if not found
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
unsigned int idx;

for (idx = 0; head && idx < index; idx++)
head = head->next;

return (head);
}

/**
* insert_dnodeint_at_index - Inserts a new node at a given index
* @h: Pointer to a pointer to the head of the list
* @idx: Index at which to insert the new node
* @n: Value for the new node
* Return: Address of the new node, or NULL on failure
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *tmp_node;

if (!h)
return (NULL);

if (idx == 0)
return (add_dnodeint(h, n));

tmp_node = get_dnodeint_at_index(*h, idx - 1);
if (!tmp_node)
return (NULL);

if (!tmp_node->next)
return (add_dnodeint_end(h, n));

new_node = malloc(sizeof(dlistint_t));
if (!new_node)
return (NULL);

new_node->n = n;
new_node->prev = tmp_node;
new_node->next = tmp_node->next;
tmp_node->next->prev = new_node;
tmp_node->next = new_node;

return (new_node);
}
