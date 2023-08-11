#include <stdio.h>
/**
 * main - Program entry point
 * description - Program that prints the alphabet in lowercase
 * followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char lower_case_letter = 'a'; /* letter 'a' is the starting point */

	do {
		putchar(lower_case_letter);
		lower_case_letter++;
	} while (lower_case_letter <= 'z');

	putchar('\n');

	return (0);
}
