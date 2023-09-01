#include "main.h"
#include <stddef.h>

/**
 * _strcpy - program makes a copy of a string
 * @dest: buffer address
 * @src: string address
 *
 * Return: will return dest
 */

char *_strcpy(char *dest, char *src)
{
unsigned long int index;

for (index = 0; src[index] != '\0'; index++)
{
dest[index] = src[index];
}

dest[index] = '\0';  /* Null-terminate the destination string */
return (dest);
}
