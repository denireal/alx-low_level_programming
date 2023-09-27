#include "lists.h"

/**
* free_listint2 - Frees a linked list and sets the head pointer to NULL.
* @head: Pointer to the pointer to the listint_t list to be freed.
*/
void free_listint2(listint_t **head)
{
listint_t *temp;
listint_t *curr;

if (head != NULL)
{
curr = *head;
while ((temp = curr) != NULL)
{
curr = curr->next;
free(temp);
}
*head = NULL;
}
}
