#include "main.h"
#include <ctype.h>
#include <stdbool.h>

/**
 *cap_string - capitalizes every word of a string
 *@str: string to modify str.
 *
 *Return: the resulting string (str)
 */

char *cap_string(char *str)
{
	int i = 0;

	bool new_word = true;

	for (; str[i] != '\0'; i++)
	{
		if (isspace(str[i]) || ispunct(str[i]))
		{
			new_word = true;
		}
		else if (new_word && islower(str[i]))
		{
			str[i] = toupper(str[i]);
			new_word = false;
		}
		else
		{
			new_word = false;
		}
	}
	return (str);
}
