#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/**
 * main - Function multiplies two positive numbers.
 * @argc: Number of arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	unsigned long mul;
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		return (98);
	}

	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
			{
				printf("Error\n");
				return (98);
			}
		}
	}
	mul = atol(argv[1]) * atol(argv[2]);

	if (mul > ULONG_MAX)
	{
		printf("Error\n");
		return (98);
	}
	printf("%lu\n", mul);
	return (0);
}
