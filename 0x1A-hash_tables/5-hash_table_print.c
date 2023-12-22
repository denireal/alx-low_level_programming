#include "hash_tables.h"

/**
* print_list - Prints the key-value pairs in a linked list.
* @h: A pointer to the head of the linked list.
*/
void print_list(hash_node_t *h)
{
for (; h; h = h->next)
{
printf("'%s': '%s'", h->key, h->value);
if (h->next)
printf(", ");
}
}

/**
* hash_table_print - Prints the entire hash table.
* @ht: A pointer to the hash table.
*/
void hash_table_print(const hash_table_t *ht)
{
unsigned long int i, index;
hash_node_t *node = NULL;

if (!ht)
return;

printf("{");

for (i = 0; i < ht->size; i++)
{
if (ht->array[i] != NULL)
{
node = ht->array[i];
index = key_index((const unsigned char *)node->key, ht->size);
break;
}
}

if (node)
{
for (i = 0; i < ht->size; i++)
{
if (ht->array[i] != NULL)
{
print_list(ht->array[i]);

if (i < index)
printf(", ");
}
}
}

printf("}\n");
}
