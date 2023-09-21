#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * add_node_end - appends a new node at the end of a linked list
 * @head: double pointer to the list_t list
 * @str: string to assign to the new node
 *
 * Description: This function creates a new node, assigns the provided string
 * to it, and appends it at the end of the linked list. It returns a pointer
 * to the newly added node, or NULL if it fails to allocate memory or duplicate
 * the string.
 *
 * Return: On success, it returns the address of the new node. On failure, it
 * returns NULL.
 */
list_t *add_node_end(list_t **head, const char *str)
{
if (!str)
return (NULL);

list_t *new = malloc(sizeof(list_t));
if (!new)
return (NULL);

new->str = strdup(str);
if (!new->str)
{
free(new);
return (NULL);
}

new->len = strlen(str);
new->next = NULL;

if (!*head)
{
*head = new;
return (new);
}

list_t *temp = *head;
while (temp->next)
temp = temp->next;

temp->next = new;

return (new);
}
