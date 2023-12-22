#include "hash_tables.h"

/**
* hash_table_get - Retrieves the value associated with a key in a hash table.
* @ht: A pointer to the hash table.
* @key: The key to be looked up.
*
* Return: The value associated with the key, or NULL if the key is not found.
*/
char *hash_table_get(const hash_table_t *ht, const char *key)
{
unsigned long int key_index;
hash_node_t *current_node = NULL;

/* Check for invalid parameters */
if (!ht || !key || !strcmp(key, ""))
return (NULL);

/* Calculate the index of the key in the hash table */
key_index = key_index((const unsigned char *)key, ht->size);

/* Traverse the linked list at the calculated index */
current_node = ht->array[key_index];
while (current_node)
{
/* Check if the current node's key matches the given key */
if (!strcmp(current_node->key, key))
return (current_node->value);

/* Move to the next node in the linked list */
current_node = current_node->next;
}

/* Key not found in the hash table */
return (NULL);
}
