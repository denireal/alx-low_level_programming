#include <stdio.h>

/**
 * main - program's entry point. prints all the command-line
 * arguments it receives, one per line
 * @argc: integer representing the number of command line arguments
 * @argv: An array of strings representing the command-line arguments.
 *
 * Return: returns 0.
 */
int main(int argc, char **argv)
{
	int i = 0; /* Initialize a counter variable to 0 */

	/* Use a while loop to iterate through the command-line arguments */
	while (i < argc)
	{
	/* Print each command-line argument followed by a newline */
		printf("%s\n", argv[i]);
		i++; /* Increment the counter variable */
	}

	return (0); /* Return 0 to signify that the program executed successfully. */
}
