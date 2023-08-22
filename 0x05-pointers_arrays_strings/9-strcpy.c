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
	unsigned long int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;

		/* Check for null termination to prevent buffer overflow */
		if (i >= sizeof(dest))
			break;
	}

	dest[i] = '\0';
	return (dest);
}
