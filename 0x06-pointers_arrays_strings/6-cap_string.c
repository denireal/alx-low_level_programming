#include "main.h"

/**
 *cap_string - capitalizes every word of a string
 *@str: string to modify str.
 *
 *Return: the resulting string (str)
 */
char *cap_string(char *str)
{
	int index, spec_index;

	char special_chars[13] = {' ', '\t', '\n', ',', ';', '.',
		                              '!', '?', '"', '(', ')', '{', '}'};

	for (index = 0; str[index] != '\0'; index++)
	{
		if (index == 0 && str[index] >= 'a' && str[index] <= 'z')
		{
			str[index] -= 32;
		}

		for (spec_index = 0; spec_index < 13; spec_index++)
		{
			if (str[index] == special_chars[spec_index])
			{
				if (str[index + 1] >= 'a' && str[index + 1] <= 'z')
				{
					str[index + 1] -= 32;
				}
			}
		}
}

return (str);
}
