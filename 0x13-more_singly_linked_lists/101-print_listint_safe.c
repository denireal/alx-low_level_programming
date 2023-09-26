#include "lists.h"
#include <stdlib.h>

/**
* add_to_list - Adds a pointer to a list of pointers.
* @list: The list of pointers.
* @size: The size of the list.
* @ptr: The pointer to add to the list.
*
* Return: Pointer to the updated list.
*/
const listint_t **add_to_list(const listint_t **list, size_t size, const listint_t *ptr)
{
const listint_t **new_list;
size_t i;

new_list = malloc((size + 1) * sizeof(listint_t *));
if (new_list == NULL)
{
free(list);
exit(98);
}

for (i = 0; i < size; i++)
new_list[i] = list[i];

new_list[i] = ptr;

if (size > 0)
free(list);

return (new_list);
}

/**
* print_listint_safe - Prints a listint_t linked list, handling circular references.
* @head: Pointer to the start of the list.
*
* Return: The number of nodes in the list.
*/
size_t print_listint_safe(const listint_t *head)
{
size_t num = 0;
const listint_t **list = NULL;

while (head != NULL)
{
size_t i;

for (i = 0; i < num; i++)
{
if (head == list[i])
{
free(list);
return (num);
}
}

num++;
list = add_to_list(list, num, head);
head = head->next;
}

free(list);
return (num);
}
