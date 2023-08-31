#include "main.h"

/**
 * wildcmp - this function compare two strings using wildcards.
 * Checks whether they are identical
 * @s1: the first string
 * @s2: the second string with wildcard '*'
 *
 * Return: if the strings are identical return 1, else return 0.
 */

int wildcmp(char *s1, char *s2)
{
	char w;

	if (*s1 == '\0')
	{
		if (*s1 == '\0' && *s2 == '*')
		{
			w = wildcmp(s1, s2 + 1);
			return (w);
		}
		return (*s2 == '\0');
	}

	if (*s2 == '*')
		return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	return (0);
}
