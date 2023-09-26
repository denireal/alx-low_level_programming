#include "lists.h"

/**
* free_listint2 - Frees a linked list and sets the head pointer to NULL.
* @head: Pointer to the pointer to the listint_t list to be freed.
*/
void free_listint2(listint_t **head)
{
listint_t *temp;

if (head == NULL)
return;

/* Loop through the list, freeing each node */
while (*head)
{
temp = (*head)->next;
free(*head);
*head = temp;
}

/* Set the head pointer to NULL to indicate an empty list */
*head = NULL;
}
