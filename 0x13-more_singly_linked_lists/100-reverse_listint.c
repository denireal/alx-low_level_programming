#include "lists.h"

/**
* reverse_listint - Reverses a linked list in place.
* @head: Pointer to the pointer to the first node in the list.
*
* Return: Pointer to the new first node in the reversed list.
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *p;
listint_t *n;

p = NULL;
n = NULL;

while (*head != NULL)
{
n = (*head)->next;
(*head)->next = p;
p = *head;
*head = n;
}

*head = p;
return (*head);
}
