#include <stdio.h>

/**
 * main - Program entry point
 * description - Program that prints the alphabet in lowercase without q and e
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lowercase_letter = 'a';

	/* This section print the lower case letters without q and e */
	while (lowercase_letter <= 'z')
	{
		if (lowercase_letter != 'q' && lowercase_letter != 'e')
		{
			putchar(lowercase_letter);
		}

		lowercase_letter++;
	}

	putchar('\n');

	return (0);
}
