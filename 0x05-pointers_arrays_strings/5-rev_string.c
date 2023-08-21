#include "main.h"
#include <string.h>

/**
 * rev_string - program reverses a string.
 * @s: input string to be reversed.
 *
 * Return: will retun void
 */

void rev_string(char *s)
{
	int length = strlen(s);
	int start_index = 0;
	int end_index = length - 1;
	char tmp;

	while (start_index < end_index)
	{
		/* Swap characters at start and end positions */
		tmp = s[start_index];
		s[start_index] = s[end_index];
		s[end_index] = tmp;

		/* Move start and end indices towards each other */
		start_index++;
		end_index--;
	}
}
