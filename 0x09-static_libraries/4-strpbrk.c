#include <stddef.h>

/**
* in_accept - determines if a given character is in the accept string
* @c: character to be checked
* @accept: string containing the only accepted characters
*
* Return: 1 if c is in accept string, else return 0
*/
int in_accept(char c, const char *accept)
{
	size_t i;

	for (i = 0; accept[i] != '\0'; i++)
	{
		if (c == accept[i])
			return (1);
	}

	return (0);
}

/**
* _strpbrk - this func. searches the string for set of bytes
* @s: string to be checked
* @accept: containing accepted bytes
*
* Return:  returns a pointer to a byte within the string s that corresponds to
* any of the bytes present in the accept string. If no such matching byte is
* found, the function returns NULL.
*/
char *_strpbrk(char *s, const char *accept)
{
	size_t i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (in_accept(s[i], accept))
		{
			return (s + i);
		}
	}
	return (NULL);
}
