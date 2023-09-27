#include "lists.h"

/**
* free_listint - Frees a linked list.
* @head: Pointer to the first element of the list to be freed.
*/
void free_listint(listint_t *head)
{
listint_t *temp;

while ((temp = head) != NULL)
{
head = head->next;
free(temp);
}
}
