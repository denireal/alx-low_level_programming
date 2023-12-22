#include "hash_tables.h"

/**
* key_index - Computes the index of a key in a hash table.
* @key: The key string.
* @size: The size of the hash table array.
*
* Return: The computed index of the key in the hash table.
*/
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
unsigned long int hash_value;

if (size == 0)
return (0);

/* Compute the hash value using the DJB2 hash function */
hash_value = hash_djb2(key);

/* Return the index of the key within the hash table array */
return (hash_value % size);
}
