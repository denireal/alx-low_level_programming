#include "main.h"
#include <stddef.h>

/**
 * _strchr - finds char in string
 * @s: this is the pointer to string
 * @c: char to be located
 *
 * Return: returns the pointer to the first occurrence
 * of character 'c' within string 's'.
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (NULL);
}

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
