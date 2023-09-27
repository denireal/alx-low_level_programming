#include "lists.h"
/**
* print_listint_safe - function that prints a linked list.
* @head: the list head.
*
* Return: number of list nodes.
*/
size_t print_listint_safe(const listint_t *head)
{
size_t count = 0;

while (head != NULL)
{
printf("%d\n", head->n);
count++;

if (head <= head->next)
{
fprintf(stderr, "Error: Infinite loop detected\n");
exit(98);
}

head = head->next;
}

return (count);
}
