#include "lists.h"

/**
* insert_nodeint_at_index - Inserts a new node at a given position
* in a linked list.
* @head: Pointer to a pointer to the head of the list.
* @idx: The index where the new node should be inserted (starting from 0).
* @n: The integer value to be stored in the new node.
*
* Return: The address of the new node, or NULL if it fails.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node, *temp;
unsigned int i;

if (head == NULL)
return (NULL);

if (idx == 0)
{
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = *head;
*head = new_node;
return (new_node);
}

temp = *head;
for (i = 0; i < idx - 1 && temp != NULL; i++)
temp = temp->next;

if (temp == NULL)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);
new_node->n = n;
new_node->next = temp->next;
temp->next = new_node;

return (new_node);
}
