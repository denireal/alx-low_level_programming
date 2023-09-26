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
listint_t *new_node = malloc(sizeof(listint_t));
listint_t *temp = *head;

if (!new_node || !head)
return (NULL);

new_node->n = n;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

for (unsigned int i = 0; temp; i++)
{
if (i == idx - 1)
{
new_node->next = temp->next;
temp->next = new_node;
return (new_node);
}
temp = temp->next;
}

free(new_node);
return (NULL);
}
