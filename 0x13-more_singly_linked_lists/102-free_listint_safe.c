#include "lists.h"

/**
* free_list - To free a linked list
* @head: head of a list.
*
* Return: return 0.
*/
void free_list(listp_t **head)
{
listp_t *tmp;
listp_t *current;

if (head != NULL)
{
current = *head;
while ((tmp = current) != NULL)
{
current = current->next;
free(tmp);
}
*head = NULL;
}
}

/**
* free_listint_safe - To free a linked list.
* @h: list head.
*
* Return: size of the freed list.
*/
size_t free_listint_safe(listint_t **h)
{
size_t count = 0;
listp_t *ptr, *new_ptr, *scan;
listint_t *current_node;

ptr = NULL;
while (*h != NULL)
{
new_ptr = malloc(sizeof(listp_t));

if (new_ptr == NULL)
exit(98);

new_ptr->p = (void *)*h;
new_ptr->next = ptr;
ptr = new_ptr;

scan = ptr;

while (scan->next != NULL)
{
scan = scan->next;
if (*h == scan->p)
{
*h = NULL;
free_list(&ptr);
return (count);
}
}

current_node = *h;
*h = (*h)->next;
free(current_node);
count++;
}

*h = NULL;
free_list(&ptr);
return (count);
}
