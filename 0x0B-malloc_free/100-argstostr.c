#include "main.h"

/**
 * concatenate_strings - Concatenate two strings with a separator.
 * @dest: Destination string.
 * @src: Source string to concatenate.
 * @separator: The separator to add between dest and src.
 *
 * Return: Pointer to the concatenated string.
 */
char *concatenate_strings(char *dest, const char *src, const char *separator)
{
	strcat(dest, src);
	strcat(dest, separator);
	return (dest);
}

/**
 * argstostr - Concatenate command-line arguments into a single string.
 * @ac: The argument count.
 * @av: The argument vector.
 *
 * Return: A pointer to the concatenated string, or NULL on failure.
 */
char *argstostr(int ac, char **av)
{
	int len = 0;
	int i;
	char *combined_string;

	if (ac <= 0 || av == NULL)
		return (NULL);

	/* Calculate the total length */
	for (i = 0; i < ac; i++)
	{
		if (av[i])
		{
			len += strlen(av[i]) + 1;
			/* +1 for newline or null terminator */
		}
	}
	/* Allocate memory for the combined string */
	combined_string = (char *)malloc(len * sizeof(char));
	if (combined_string == NULL)
		return (NULL);

	/* Initialize the combined string with an empty string */
	combined_string[0] = '\0';

	/* Concatenate the arguments into the combined string */
	for (i = 0; i < ac; i++)
	{
		if (av[i])
		{
			concatenate_strings(combined_string, av[i], "\n");
			if (i < ac - 1)
			{
				concatenate_strings(combined_string, "\n", "");
			}
		}
	}
	return (combined_string);
}
