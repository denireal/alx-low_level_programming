#include <stdio.h>
#include <stdlib.h>

/**
 * print_main_opcode - Prints the opcode of the main function.
 * @bytes: Number of bytes to print.
 */
void print_main_opcode(int bytes)
{
	int i;
	unsigned char *main_function;

	main_function = (unsigned char *)print_main_opcode;

	for (i = 0; i < bytes; i++)
	{
		printf("%02hhx ", main_function[i]);
	}
	printf("\n");
}

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 or 2 on failure.
 */
int main(int argc, char *argv[])
{
	int bytes;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <number_of_bytes>\n", argv[0]);
		return (1);
	}
	
	bytes = atoi(argv[1]);
	if (bytes <= 0)
	{
		fprintf(stderr, "Error: Number of bytes must be a positive integer.\n");
		return (2);
	}
	if (bytes > 21)
	{
		fprintf(stderr, "Error: Number of bytes cannot exceed 21.\n");
		return (2);
	}
	print_main_opcode(bytes);
	return (0);
}
