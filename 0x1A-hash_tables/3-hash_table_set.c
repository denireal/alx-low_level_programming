#include "hash_tables.h"

/**
* replace_value - Replaces the value associated with a key in the hash table.
* @ht: A pointer to the hash table.
* @key: The key to be replaced.
* @new_value: The new value to be assigned.
*/
void replace_value(hash_node_t **ht, const char *key, const char *new_value)
{
hash_node_t *current_node = *ht;

for (; current_node && strcmp(current_node->key, key); current_node = current_node->next)
continue;

free(current_node->value);
current_node->value = strdup(new_value);
}

/**
* check_key - Checks if a key exists in the hash table.
* @ht: A pointer to the hash table.
* @key: The key to be checked.
*
* Return: 1 if the key exists, 0 otherwise.
*/
int check_key(hash_node_t *ht, const char *key)
{
for (; ht; ht = ht->next)
{
if (!strcmp(ht->key, key))
return (1);
}

return (0);
}

/**
* add_node - Adds a new node to the hash table.
* @head: A pointer to the head of the linked list.
* @key: The key of the new node.
* @value: The value of the new node.
*
* Return: A pointer to the newly added node.
*/
hash_node_t *add_node(hash_node_t **head, const char *key, const char *value)
{
hash_node_t *new_node;

new_node = malloc(sizeof(hash_node_t));
if (!new_node)
return (NULL);

new_node->key = strdup(key);
new_node->value = strdup(value);

if (*head == NULL)
{
(*head) = new_node;
new_node->next = NULL;
}
else
{
new_node->next = (*head);
(*head) = new_node;
}

return (*head);
}

/**
* hash_table_set - Adds or updates a key-value pair in the hash table.
* @ht: A pointer to the hash table.
* @key: The key to be added or updated.
* @value: The value to be associated with the key.
*
* Return: 1 if successful, 0 otherwise.
*/
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;

if (!ht || !key || !strcmp(key, "") || !value)
return (0);

index = key_index((unsigned char *)key, ht->size);

if (check_key(ht->array[index], key))
{
replace_value(&ht->array[index], key, value);
return (1);
}

add_node(&ht->array[index], key, value);
if (&ht->array[index] == NULL)
return (0);

return (1);
}
