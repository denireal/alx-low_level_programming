#include "main.h"
#include <stddef.h>

/**
 * _strspn - determines the length of the prefix substring
 * @s: string to be checked
 * @accept: set of bytes forming the prefix
 *
 * Return: integer length of the substring
 */
unsigned int _strspn(char *s, char *accept)
{
	int i = 0;

	while (*s && _strchr(accept, *s))
	{
		s++;
		i++;
	}
	return (i);
}
