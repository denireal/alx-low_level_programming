#include "main.h"

/**
 * _pow_recursion - print factorial of a number recursively
 * @x: the base variavle
 * @y: the exponent variable
 *
 * Return: the value of x raised y
 */
int _pow_recursion(int x, int y)
{
	if (y == 0)
		return (1);
	else if (y < 0)
		return (-1);
	else if (y == 1)
		return (x);
	return (x *= _pow_recursion(x, y - 1));
}
