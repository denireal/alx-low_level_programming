#include "lists.h"

/**
 * add_nodeint - Inserts a new node at the beginning of a linked list.
 * @head: Pointer to the pointer to the first node in the list.
 * @n: The data to be inserted into the new node.
 *
 * Return: Pointer to the new node, or NULL if memory allocation fails.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

/* Allocate memory for the new node */
new_node = malloc(sizeof(listint_t));
if (!new_node)
return (NULL);

/* Initialize the new node with data and the current head as the next node */
new_node->n = n;
new_node->next = *head;

/* Update the head to point to the new node */
*head = new_node;

return (new_node);
}
