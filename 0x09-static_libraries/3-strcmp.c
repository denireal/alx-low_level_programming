#include "main.h"

/**
*_strcmp - Compares two strings.
*@s1: The first string.
*@s2: The second string.
*
*Return: Difference between the ASCII values of the non-matching characters.
*/
int _strcmp(char *s1, char *s2)
{
while (*s1 && (*s1 == *s2))
{
s1++;
s2++;
}

return (*s1 - *s2);
}
