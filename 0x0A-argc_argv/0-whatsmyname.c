#include <stdio.h>

/**
* main - program that prints the name of the program
* (the first command line argument) followed by a newline character.
* @argc: integer representing the number of command line arguments.
* @argv: array of strings representing the command line arguments
*
* Return: Always 0 (Success)
*/
int main(int argc, char **argv)
{
	printf("%s\n", argv[0]);
	(void)argc;

	return (0);
}
