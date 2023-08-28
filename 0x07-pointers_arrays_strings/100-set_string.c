#include "main.h"

/**
* set_string - Updates the value of a pointer to a char.
* @s: Pointer to a pointer that will update the string.
* @to: Pointer to the string to be copied.
*
* Return: will retun void
*/

void set_string(char **s, char *to)
{
	int i = 0;

	if (*s != NULL)
	{
		for (; (*s)[i] != '\0'; i++)
		{
			(*s)[i] = '\0';
		}
	}

	for (; to[i] != '\0'; i++)
	{
		(*s)[i] = to[i];
	}
}
