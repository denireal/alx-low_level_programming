#include <stdlib.h>
#include "lists.h"

/**
 * free_list - releases the memory occupied by a linked list
 * @head: pointer to the beginning of the list_t list
 *
 * Description: This function iterates through a linked list, releasing the
 * memory allocated for each node and the associated string data. It starts
 * from the provided head and continues until the end of the list is reached.
 */

void free_list(list_t *head)
{
list_t *current;

for (; head != NULL; head = current)
{
current = head->next;
free(head->str);
free(head);
}
}
