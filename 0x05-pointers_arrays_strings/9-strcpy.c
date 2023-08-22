#include "main.h"

/**
 * _strcpy - program makes a copy of a string
 * @dest: buffer address
 * @src: string address
 *
 * Return: will return dest
 */

char *_strcpy(char *dest, char *src)
{
	int a = 0;

	while (*src != '\0')
	{
		dest[a] = *src;
		a++;
		src++;
	}
	return (dest);
}
