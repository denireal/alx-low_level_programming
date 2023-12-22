#include "hash_tables.h"

/**
* hash_djb2 - Implements the DJB2 hash function.
* @str: The string to be hashed.
*
* Return: The hash value.
*/
unsigned long int hash_djb2(const unsigned char *str)
{
unsigned long int hash;  /* Hash value to be calculated */
size_t ch;               /* Current character in the string */

hash = 5381;

/* Loop through each character in the string */
do
{
ch = *str++;
hash = ((hash << 5) + hash) + ch;  /* Update the hash value */
} while (ch != 0);  /* Continue until null terminator is encountered */

return (hash);
}
