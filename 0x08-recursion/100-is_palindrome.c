#include "main.h"
#include <stdbool.h>

/**
 * _strlen_recursion - Calculates the length of a string.
 * @s: A string for which the length is to be calculated.
 *
 * Return: The length of string @s.
 */
int _strlen_recursion(char *s)
{
	if (!*s)
	{
		return (0);
	}
	return (_strlen_recursion(s + 1) + 1);
}

/**
 * _is_palindrome_recursive - Checks if a string is a palindrome.
 * @s: The input string to be checked.
 * @start: The starting index for comparison.
 * @end: The ending index for comparison.
 *
 * Return: true if the string is a palindrome, false otherwise.
 */
bool _is_palindrome_recursive(char *s, int start, int end)
{
	if (start >= end)
	{
		return (true);
	}
	if (s[start] != s[end])
	{
		return (false);
	}
	return (_is_palindrome_recursive(s, start + 1, end - 1));
}

/**
 * is_palindrome - Checks if a string is a palindrome.
 * @s: The input string to be checked.
 *
 * Return: true if the string is a palindrome, false otherwise.
 */
int is_palindrome(char *s)
{
	int length;

	length = _strlen_recursion(s);
	return (_is_palindrome_recursive(s, 0, length - 1));
}
