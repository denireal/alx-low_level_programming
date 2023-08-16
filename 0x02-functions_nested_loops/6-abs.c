#include "main.h"

/**
 * _abs - Determine absolute value of an integer
 * @n: The parameter to be checked
 *
 * Return: absolute value
 */
int _abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}
