#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "lists.h"

/**
 * add_node - inserts a new node at the beginning of a linked list
 * @head: double pointer to the list_t list
 * @str: the string to be added as the value in the new node
 *
 * Description: This function creates a new node, assigns the provided string
 * to it, and inserts it at the beginning of the linked list. It returns a
 * pointer to the newly added node, or NULL if it fails to allocate memory
 * or duplicate the string.
 *
 * Return: On success, it returns the address of the new node. On failure, it
 * returns NULL.
 */
list_t *add_node(list_t **head, const char *str)
{
list_t *new;
unsigned int len;

if (!str)
return (NULL);

len = 0;
while (str[len])
len++;

new = malloc(sizeof(list_t));
if (!new)
return (NULL);

new->str = strdup(str);
if (!new->str)
{
free(new);
return (NULL);
}

new->len = len;
new->next = *head;
*head = new;

return (*head);
}
