#include "lists.h"

/**
* insert_nodeint_at_index - Inserts a new node at a specified position in a linked list.
* @head: Pointer to the pointer to the first node in the list.
* @idx: The index where the new node is to be inserted.
* @n: The data to insert in the new node.
*
* Return: Pointer to the new node, or NULL on failure.
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *temp = *head;

	new = malloc(sizeof(listint_t));
	if (!new || !head)
		return (NULL);

	new->n = n;
	new->next = NULL;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	for (i = 0; temp && i < idx; i++)
	{
		if (i == idx - 1)
		{
			new->next = temp->next;
			temp->next = new;
			return (new);
		}
		else
			temp = temp->next;
	}

	return (NULL);
}
