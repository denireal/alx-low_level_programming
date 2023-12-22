#include "hash_tables.h"

/**
* free_list - Frees the memory allocated for a linked list.
* @head: A pointer to the head of the linked list.
*/
void free_list(hash_node_t *head)
{
hash_node_t *current;

while (head)
{
current = head->next;
free(head->key);
free(head->value);
free(head);
head = current;
}
}

/**
* hash_table_delete - Deletes a hash table and frees its memory.
* @ht: A pointer to the hash table.
*/
void hash_table_delete(hash_table_t *ht)
{
unsigned long int i;

if (!ht)
return;

/* Free the memory allocated for each linked list in the hash table */
for (i = 0; i < ht->size; i++)
free_list(ht->array[i]);

/* Free the memory allocated for the array of linked lists */
free(ht->array);

/* Free the memory allocated for the hash table itself */
free(ht);
}
