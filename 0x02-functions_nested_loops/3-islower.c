#include "main.h"

/**
 * _islower - Program checks whether character is lowercase
 * @c: the character to be checked
 *
 * Return: The boolean value - either 1 or 0
 */
int _islower(int c)
{
	char lowercase_alpha = 'a';
	int bool_value = 0;

	for (; lowercase_alpha <= 'z'; bool_value++)
	{
		if (lowercase_alpha == c)
		{
			bool_value = 1;
			lowercase_alpha++;
		}
	}
	return (bool_value);
}
