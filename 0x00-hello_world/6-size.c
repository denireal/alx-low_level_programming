#include <stdio.h>
/**
 * main - Program entry point
 * print the size of various types
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	/* Declaration section */
	int char_size = sizeof(char);
	int int_size = sizeof(int);
	int long_int_size = sizeof(long int);
	int long_long_int_size = sizeof(long long int);
	int float_size = sizeof(float);

	printf("Size of a char: %d byte(s)\n", char_size);
	printf("Size of an int: %d byte(s)\n", int_size);
	printf("Size of a long int: %d byte(s)\n", long_int_size);
	printf("Size of a long long int: %d byte(s)\n", long_long_int_size);
	printf("Size of a float: %d byte(s)\n", float_size);
	return (0);
}
