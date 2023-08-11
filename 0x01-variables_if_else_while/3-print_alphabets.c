#include <stdio.h>
/**
 * main - Program entry point
 * description - Program that prints the alphabet in lowercase
 * and then in uppercase, followed by a new line
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
	char lowercase_letter = 'a';
	char uppercase_letter = 'A';

	do {
		putchar(lowercase_letter);
		lowercase_letter++;
	} while (lowercase_letter <= 'z');

	do {
		putchar(uppercase_letter);
		uppercase_letter++;
	} while (uppercase_letter <= 'Z');

	putchar('\n');

	return (0);
}
