#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - Multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char *argv[])
{
	unsigned long result; /* Variable to store the result of multiplication */
	int arg_index = 1, char_index;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	while (arg_index < argc)
	{
		char_index = 0;
		while (argv[arg_index][char_index] != '\0')
		{
			if (argv[arg_index][char_index] > '9' || argv[arg_index][char_index] < '0')
			{
				printf("Error\n");
				return (98);
			}
			char_index++;
		}
		arg_index++;
	}

	result = strtoul(argv[1], NULL, 10) * strtoul(argv[2], NULL, 10);
	printf("%lu\n", result); /* Print the result */
	return (0);
}
