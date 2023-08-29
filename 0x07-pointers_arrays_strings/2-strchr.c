#include <string.h>
#include "main.h"
/**
* _strchr - function locate a character in a string.
* @s: the string to search.
* @c: the character to locate.
*
* Return: returns a pointer to the first occurrence of character c
* in the string s, or NULL if the character is not found.
*/
char *_strchr(char *s, char c)
{
	for (; *s != '\0'; s++)
	{
		if (*s == c)
			return (s);
	}
	if (c =='\0')
		return (s);

	return (NULL);
}
