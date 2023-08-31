#include "main.h"
/**
 * _print_rev_recursion - function prints a string in reverse
 * using recursion
 * @s: the input string to be printed
 *
 * Return: will return void
 */
void _print_rev_recursion(char *s)
{
        if (*s)
        {
                _print_rev_recursion(s + 1);
                _putchar(*s);
        }
}
