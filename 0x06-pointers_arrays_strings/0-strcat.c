#include "main.h"

/**
 *_strcat - function to concatenate (join)
 *two string
 *@dest: destination
 *@src: source
 *
 *Return: return dest
 */

char *_strcat(char *dest, char *src)
{
char *ptr = dest;
int count  = 0;

while (*ptr)
{
ptr++;
}

for (; src[count] != '\0'; count++)
{
*ptr++ = src[count];
}

*ptr = '\0';

return (dest);
}
