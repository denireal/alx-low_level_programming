#include "lists.h"

/**
* add_nodeint_end - Adds a new node at the end of a linked list.
* @head: A pointer to the pointer to the first element in the list.
* @n: The data to be placed in the new element.
*
* Return: A pointer to the new node, or NULL on memory allocation failure.
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *temp = *head;

/* Allocate memory for the new node */
new_node = malloc(sizeof(listint_t));
if (!new_node)
return (NULL);

/* Initialize the new node with data and set its next pointer to NULL */
new_node->n = n;
new_node->next = NULL;

/* Handle the case when the list is initially empty */
if (*head == NULL)
{
*head = new_node;
return (new_node);
}

/* Traverse the list to locate the last node */
while (temp->next)
temp = temp->next;

/* Attach the new node to the end of the list */
temp->next = new_node;

return (new_node);
}
