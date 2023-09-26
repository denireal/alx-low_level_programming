#include "lists.h"

/**
* sum_listint - Calculates the sum of all data elements in a listint_t list.
* @head: Pointer to the first node in the linked list.
*
* Return: The resulting sum of all data elements.
*/
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *temp = head;

/* Traverse the list and accumulate the sum */
while (temp)
{
sum += temp->n;
temp = temp->next;
}

return (sum);
}
