#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <errno.h>
#include <inttypes.h>

/**
 * is_digit_str - Checks if a string contains only digits.
 * @str: The input string to check.
 *
 * Return: (1) if the string contains only digits, (0) otherwise.
 */
int is_digit_str(const char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

/**
 * exit_error - Prints an error message and exits with status 98.
 */

void exit_error(void)
{
	printf("Error\n");
	exit(98);
}

/**
 * parse_ull - Parses and validates an unsigned long long integer
 * from a string.
 * @str: The input string to parse and validate.
 *
 * Return: The parsed and validated unsigned long long integer.
 */

long unsigned int parse_ull(const char *str)
{
	char *endptr;
	long unsigned int num;

	errno = 0;

	num = strtoull(str, &endptr, 10);
	if (errno != 0 || *endptr != '\0' || num == 0)
	{
		exit_error();
	}
	return (num);
}

/**
 * main - Entry point. Multiplies two positive numbers.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * Return: (0) on success, (98) on error.
 */

int main(int argc, char *argv[])
{
	unsigned long num1;
        unsigned long num2;
        unsigned long product;

	if (argc != 3 || !is_digit_str(argv[1])
			|| !is_digit_str(argv[2]))
	{
		exit_error();
	}

	num1 = parse_ull(argv[1]);
	num2 = parse_ull(argv[2]);

	asm("mul %1" : "=A"(product) : "r"(num1), "0"(num2));
	printf("Result: %" PRIu64 "\n", product);

	return (0);
}
