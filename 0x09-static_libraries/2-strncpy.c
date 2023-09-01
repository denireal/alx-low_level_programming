#include "main.h"

/**
*_strncpy - function copies a string
*@dest: destination
*@src: source
*@n: maximum number of bytes to copied
*
* Return: return string dest.
*/
char *_strncpy(char *dest, char *src, int n)
{
int src_index;

for (src_index = 0; src_index < n && src[src_index]; src_index++)
{
dest[src_index] = src[src_index];
}

for (; src_index < n; src_index++)
{
dest[src_index] = '\0';
}

return (dest);
}
