#include "hash_tables.h"

/**
* hash_table_create - Creates a hash table.
* @size: The size of the array.
*
* Return: A pointer to the newly created hash table, or NULL if it fails.
*/
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t *new_hash_table;

/* Check for zero or negative size */
if (size == 0 || size == (unsigned long int)-1)
return (NULL);

/* Allocate memory for the hash table structure */
new_hash_table = (hash_table_t *)malloc(sizeof(hash_table_t));
if (!new_hash_table)
return (NULL);

/* Set the size of the hash table */
new_hash_table->size = size;

/* Allocate memory for the array of hash nodes */
new_hash_table->array = calloc((size_t)new_hash_table->size,
sizeof(hash_node_t *));
if (!new_hash_table->array)
{
free(new_hash_table); /* Free the allocated hash_table_t on failure */
return (NULL);
}

return (new_hash_table);
}
