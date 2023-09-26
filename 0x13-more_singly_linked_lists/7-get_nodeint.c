#include "lists.h"

/**
* get_nodeint_at_index - Retrieves the node at a specified index in a linked list.
* @head: Pointer to the first node in the linked list.
* @index: The index of the node to retrieve.
*
* Return: Pointer to the desired node, or NULL if not found or list is empty.
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int i;
listint_t *temp = head;

for (i = 0; temp && i < index; i++)
{
temp = temp->next;
}

return (temp);
}
