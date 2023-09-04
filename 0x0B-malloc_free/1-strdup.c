#include "main.h"

/**
 * _strdup - program duplicates a string.
 * @str: the string to duplicate.
 *
 * Return: A pointer to the duplicated string, or NULL on failure.
 */
char *_strdup(char *str)
{
	char *copy;
	size_t len;
	size_t i = 0;

	if (str == NULL)
		return (NULL); /* Handle NULL input string */

	/* Calculate the length of the input string */
	len = strlen(str);

	/* Allocate memory for the copy (including the null terminator) */
	copy = malloc(len + 1);

	if (copy == NULL)
		return (NULL); /* Memory allocation failed */

	/* Copy the input string to the newly allocated memory */
	for (; i <= len; i++)
	{
		copy[i] = str[i];
	}

	return (copy);
}
