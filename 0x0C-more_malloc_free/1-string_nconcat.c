#include "main.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

/**
 * string_nconcat - concatenate two strings with a limit
 * from the second string
 * @s1: the first input string
 * @s2: the second input string
 * @n: the maximum number of characters from s2 to concatenate
 *
 * Return: a pointer to the concatenated string or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	size_t len1 = (s1 == NULL) ? 0 : strlen(s1);
	size_t len2 = (s2 == NULL) ? 0 : strlen(s2);
	size_t total_len = len1 + ((len2 < n) ? len2 : n);
	char *result = malloc(total_len + 1);

	if (result == NULL)
		return (NULL);
	strcpy(result, s1 ? s1 : "");
	strncat(result, s2 ? s2 : "", n);

	return (result);
}
