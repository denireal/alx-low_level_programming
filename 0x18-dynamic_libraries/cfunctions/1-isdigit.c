#include "main.h"

/**
 * _isdigit - program checks whether a character is digit
 * @c: variable to be checked
 *
 * Return: 1 if true, 0 if false
 */

int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);

	else
		return (0);
}
