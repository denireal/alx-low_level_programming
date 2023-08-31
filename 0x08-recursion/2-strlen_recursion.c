#include "main.h"
/**
 * _strlen_recursion - function prints the length of a string
 * recursively
 * @s: the input string to be printed
 *
 * Return: string length
 */
int _strlen_recursion(char *s)
{
	if (*s)
	{
		return (1 + _strlen_recursion(s + 1));
	}
	return (0);
}
