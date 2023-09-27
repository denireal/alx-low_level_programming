#include "lists.h"

/**
* reverse_listint - Reverses a linked list in place.
* @head: Pointer to the pointer to the first node in the list.
*
* Return: Pointer to the new first node
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *temp;

if (*head == NULL || (*head)->next == NULL)
{
return *head;
}

temp = (*head)->next;
(*head)->next = prev;
prev = *head;
*head = temp;

reverse_listint(head);

return (prev);
}
