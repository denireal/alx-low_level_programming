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
listint_t *new;

new = malloc(sizeof(listint_t));

if (new == NULL)
return (NULL);

new->n = n;
new->next = *head;
*head = new;

return (*head);
}
