#include "lists.h"

/**
* insert_nodeint_at_index - Inserts a new node at a specified position in a linked list.
* @head: Pointer to the pointer to the first node in the list.
* @idx: The index where the new node is to be inserted.
* @n: The data to insert in the new node.
*
* Return: Pointer to the new node, or NULL on failure.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int i;
listint_t *new;
listint_t *h;

h = *head;

if (idx != 0)
{
for (i = 0; i < idx - 1 && h != NULL; i++)
{
h = h->next;
}
}

if (h == NULL && idx != 0)
return (NULL);

new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);

new->n = n;

if (idx == 0)

if (idx == 0)
{
new->next = *head;
*head = new;
}
else
{
new->next = h->next;
h->next = new;
}

return (new);
}
