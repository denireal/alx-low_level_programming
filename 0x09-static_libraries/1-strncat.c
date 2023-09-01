#include "main.h"

/**
* _strncat - function to oncatenate n bytes from
* src to the end of dest
* @dest: destination string
* @src: source string
* @n: maximum number of bytes to concatenate
*
* Return: returns string dest
*/

char *_strncat(char *dest, char *src, int n)
{
int src_index = 0;
char *dest_ptr = dest;

while (*dest_ptr != '\0')
{
dest_ptr++;
}

for (; src_index < n && src[src_index] != '\0'; src_index++)
{
*dest_ptr = src[src_index];
dest_ptr++;
}

*dest_ptr = '\0';

return (dest);
}
