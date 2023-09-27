#include "lists.h"

/**
* pop_listint - Deletes the head node of a linked list.
* @head: Pointer to the pointer to the first element in the linked list.
*
* Return: The data inside the deleted element, or 0 if the list is empty.
*/
int pop_listint(listint_t **head)
{
int h_node;
listint_t *h;
listint_t *curr;

if (*head == NULL)
return (0);

curr = *head;

h_node = curr->n;

h = curr->next;

free(curr);

*head = h;

return (h_node);
}
