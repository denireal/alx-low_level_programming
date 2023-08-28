#include <string.h>

/**
* 
* _strspn - gets the length of a prefix substring
* @s: string to check
* @accept: string containing the only accepted characters
*
* Return: the number of bytes in the initial segment of s which consist
* only of bytes from accept
*/

unsigned int _strspn(char *s, char *accept)
{
	unsigned int length = 0;

	for (; *s != '\0' && strchr(accept, *s) != NULL; s++, length++)
		continue;
	return (length);
}
