#include "lists.h"

/**
* insert_dnodeint_at_index - This insert a node in the postion
* @h: Denoting pointer to direction of the head
* @n: Denoting the integer
* @idx: Indicating position of the new node
* Return: The new node
*/
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node, *cons_node = *h;

if (idx == 0)
return (add_dnodeint(h, n));

for (; idx != 1; idx--)
{
if (cons_node == NULL)
return (NULL);
cons_node = cons_node->next;
}

if (cons_node->next == NULL)
return (add_dnodeint_end(h, n));

new_node = malloc(sizeof(dlistint_t));

if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = cons_node->next;
new_node->prev = cons_node;
new_node->next->prev = new_node;
new_node->next = new_node;

return (new_node);
}
