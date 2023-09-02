#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stdbool.h>


int is_valid_int(char *s);

/**
 * main - Entry point of the program. this function adds positive
 * integers passed as command-line arguments.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 *
 * Return: returns 0 if successful, 1 if an error occurred.
 */
int main(int argc, char **argv)
{
	int i;
	int aggreg = 0;

	if (argc < 2)
	{
		printf("%d\n", 0);
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (is_valid_int(argv[i]))
		{
			aggreg += atoi(argv[i]);
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", aggreg);
	return (0);
}
/**
 * is_valid_int - Check if a string represents a valid integer.
 * @s: The string to check.
 *
 * Return: true if the string is a valid integer, false otherwise.
 */
int is_valid_int(char *s)
{
	char *endptr;

	long num = strtol(s, &endptr, 10);

	if (*endptr != '\0' || num < INT_MIN || num > INT_MAX)
	{
		return (0);
	}
	return (1);
}
