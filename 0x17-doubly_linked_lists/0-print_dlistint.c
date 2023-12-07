#include "lists.h"

/**
* print_dlistint - Prints all elements of a doubly linked list
* @head: Pointer to the head of the list
* Return: Number of elements printed
*/
size_t print_dlistint(const dlistint_t *h)
{
size_t count = 0;
const dlistint_t *current = h;

while (current != NULL)
{
printf("%d\n", current->n);
current = current->next;
count++;
}

return (count);
}
