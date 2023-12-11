#include "main.h"

/**
 * _isupper - program checks whether a character is uppercase
 * @c: integer variable to be checked
 * Return: 1 if true, 0 if false
 */
int _isupper(int c)
{
	if (c > 64 && c < 91)
	{
		return (1);
	}
	return (0);
}
