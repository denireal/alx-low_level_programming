#include "lists.h"

/**
* free_listp - to free a linked list
* @head: list head.
*
* Return: return 0.
*/
void free_listp(listp_t **head)
{
listp_t *temp;
listp_t *curr;

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

/**
* print_listint_safe - function that prints a linked list.
* @head: the list head.
*
* Return: number of list nodes.
*/
size_t print_listint_safe(const listint_t *head)
{
size_t new_nodes = 0;
listp_t *head_ptr, *new, *add;

head_ptr = NULL;
while (head != NULL)
{
new = malloc(sizeof(listp_t));

if (new == NULL)
exit(98);

new->p = (void *)head;
new->next = head_ptr;
head_ptr = new;

add = hptr;

while (add->next != NULL)
{
add = add->next;
if (head == add->p)
{
printf("-> [%p] %d\n", (void *)head, head->n);
free_listp(&head_ptr);
return (new_nodes);
}
}

printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
new_nodes++;
}

free_listp(&head_ptr);
return (new_nodes);
}
