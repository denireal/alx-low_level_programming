#include <stdio.h>

/**
* main - prints the name of the program
* (the first command line argument) followed by a newline character
* @argc: integer representing the number of command line arguments
* @argv: array of strings (char pointers) representing the
* command line arguments
*
* Return: Always 0 (Success)
*/

int main(int argc, char **argv)
{
	printf("%d\n", argc - 1);
	(void)argv;
	return (0);
}
