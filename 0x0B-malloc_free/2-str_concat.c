#include "main.h"

/**
 * str_concat - program concatenates two strings.
 * @s1: the first string.
 * @s2: the second string.
 *
 * Return: returns a pointer to the concatenated string, or NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	char *result;
	size_t len1, len2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = strlen(s1);
	len2 = strlen(s2);

	result = malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);

	strcpy(result, s1);
	strcat(result, s2);

	return (result);
}
