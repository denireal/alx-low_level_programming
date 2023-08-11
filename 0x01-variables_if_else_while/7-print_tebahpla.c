#include <stdio.h>

/**
 * main - Program entry point
 * description - program that prints the lowercase alphabet in reverse
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char reversed_lowercase_letter = 'z';

	while (reversed_lowercase_letter >= 'a')
	{
		putchar(reversed_lowercase_letter);
		reversed_lowercase_letter--;
	}
	putchar('\n');

	return (0);
}
