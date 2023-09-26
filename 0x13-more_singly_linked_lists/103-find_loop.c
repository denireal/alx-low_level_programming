#include "lists.h"

/**
* find_listint_loop - Finds the starting node of a loop in a linked list.
* @head: Pointer to the head of the linked list to search for a loop.
*
* Return: Address of the node where the loop starts, or NULL if no loop
* is found.
*/
listint_t *find_listint_loop(listint_t *head)
{
listint_t *tortoise = head;
listint_t *hare = head;

if (!head)
return (NULL);

while (tortoise && hare && hare->next)
{
tortoise = tortoise->next;
hare = hare->next->next;

if (tortoise == hare)
{
tortoise = head;
while (tortoise != hare)
{
tortoise = tortoise->next;
hare = hare->next;
}
return (hare);
}
}

return (NULL);
}
