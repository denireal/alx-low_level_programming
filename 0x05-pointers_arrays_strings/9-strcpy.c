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

	for (; *(src + a) != '\0'; a++)
	{
		*(dest + a) = *(src + a);
	}

	return (dest);
}
