#include "hash_tables.h"

/**
* shash_table_create - Creates a sorted hash table.
* @size: The size of the array.
*
* Return: A pointer to the newly created sorted hash table.
*/
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *new_shash_table;

if (size == 0)
return (NULL);

new_shash_table = calloc(1, sizeof(shash_table_t));
if (!new_shash_table)
return (NULL);

new_shash_table->size = size;
new_shash_table->array = calloc((size_t)new_shash_table->size,
sizeof(shash_node_t *));
if (new_shash_table->array == NULL)
{
free(new_shash_table);
return (NULL);
}

return (new_shash_table);
}

/**
* shash_table_set - Adds or updates a key-value pair in a sorted hash table.
* @ht: A pointer to the sorted hash table.
* @key: The key to be added or updated.
* @value: The value to be associated with the key.
*
* Return: 1 if successful, 0 otherwise.
*/
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
unsigned long int index;
shash_node_t *new_node;

if (!ht || !key || !strcmp(key, "") || !value)
return (0);

index = key_index((unsigned char *)key, ht->size);

if (check_key_s(ht->array[index], key))
return (replace_value_s(&ht->array[index], key, value));
new_node = add_node_s(&ht->array[index], key, value);
if (!new_node)
return (0);

insert_sort_s(new_node, ht);
return (1);
}

/**
* insert_sort_s - Inserts a node into a sorted doubly-linked list.
* @node: The node to be inserted.
* @ht: The sorted hash table.
*/
void insert_sort_s(shash_node_t *node, shash_table_t *ht)
{
shash_node_t *current_node = ht->shead;

if (!current_node || strcmp(node->key, current_node->key) < 0)
{
ht->shead = node;
if (!current_node)
ht->stail = node;
else
{
node->snext = current_node;
current_node->sprev = node;
}
return;
}

while (current_node->snext && strcmp(node->key, current_node->snext->key) >= 0)
current_node = current_node->snext;

node->sprev = current_node;
if (!current_node->snext)
ht->stail = node;
else
current_node->snext->sprev = node;
node->snext = current_node->snext;
current_node->snext = node;
}

/**
* shash_table_get - Retrieves the value associated with a key in a sorted hash table.
* @ht: A pointer to the sorted hash table.
* @key: The key to be looked up.
*
* Return: The value associated with the key, or NULL if the key is not found.
*/
char *shash_table_get(const shash_table_t *ht, const char *key)
{
unsigned long int index;
shash_node_t *current_node = NULL;

if (!ht || !key || !strcmp(key, ""))
return (NULL);

index = key_index((const unsigned char *)key, ht->size);
current_node = ht->array[index];

while (current_node)
{
if (!strcmp(current_node->key, key))
return (current_node->value);
current_node = current_node->next;
}

return (NULL);
}

/**
* shash_table_print - Prints the key-value pairs in a sorted hash table.
* @ht: A pointer to the sorted hash table.
*/
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *current_node = NULL;

if (!ht)
return;

current_node = ht->shead;

printf("{");
while (current_node)
{
printf("'%s': '%s'", current_node->key, current_node->value);
if (current_node->snext)
printf(", ");
current_node = current_node->snext;
}

printf("}\n");
}

/**
* shash_table_print_rev - Prints the key-value pairs in a sorted hash table in reverse order.
* @ht: A pointer to the sorted hash table.
*/
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *current_node = NULL;

if (!ht)
return;

current_node = ht->stail;

printf("{");
while (current_node)
{
printf("'%s': '%s'", current_node->key, current_node->value);
if (current_node->sprev)
printf(", ");
current_node = current_node->sprev;
}

printf("}\n");
}

/**
* shash_table_delete - Deletes a sorted hash table and frees its memory.
* @ht: A pointer to the sorted hash table.
*/
void shash_table_delete(shash_table_t *ht)
{
if (!ht)
return;

free_list_s(ht->shead);
free(ht->array);
free(ht);
}

/**
* replace_value_s - Replaces the value associated with a key in a sorted hash table.
* @ht: A pointer to the sorted hash table.
* @key: The key to be replaced.
* @value: The new value to be assigned.
*
* Return: 1 if successful, 0 otherwise.
*/
int replace_value_s(shash_node_t **ht, const char *key, const char *value)
{
shash_node_t *temp_node = *ht;

while (temp_node && strcmp(temp_node->key, key))
temp_node = temp_node->next;

free(temp_node->value);
temp_node->value = strdup(value);
if (!temp_node->value)
return (0);
return (1);
}

/**
* check_key_s - Checks if a key exists in a sorted hash table.
* @ht: A pointer to the sorted hash table.
* @key: The key to be checked.
*
* Return: 1 if the key exists, 0 otherwise.
*/
int check_key_s(shash_node_t *ht, const char *key)
{
while (ht)
{
if (!strcmp(ht->key, key))
return (1);
ht = ht->next;
}

return (0);
}

/**
* add_node_s - Adds a new node to a sorted doubly-linked list.
* @head: A pointer to the head of the linked list.
* @key: The key of the new node.
* @value: The value of the new node.
*
* Return: A pointer to the newly added node.
*/
shash_node_t *add_node_s(shash_node_t **head, const char *key, const char *value)
{
shash_node_t *new_node;

new_node = calloc(1, sizeof(shash_node_t));
if (!new_node)
return (NULL);

new_node->key = strdup(key);
if (!new_node->key)
{
free(new_node);
return (NULL);
}
new_node->value = strdup(value);
if (!new_node->value)
{
free(new_node);
free(new_node->key);
return (NULL);
}

if (*head == NULL)
(*head) = new_node;
else
{
new_node->next = (*head);
(*head) = new_node;
}

return (*head);
}

/**
* free_list_s - Frees the memory allocated for a sorted doubly-linked list.
* @head: A pointer to the head of the linked list.
*/
void free_list_s(shash_node_t *head)
{
shash_node_t *temp_node;

while (head)
{
temp_node = head->snext;
free(head->key);
free(head->value);
free(head);
head = temp_node;
}
}
