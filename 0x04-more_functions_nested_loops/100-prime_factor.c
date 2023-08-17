#include <stdio.h>

/**
 * main - program entry point
 *
 * Return: always 0 (sucess)
 */

int main(void)
{
	unsigned long int prime = 3;
	unsigned long int n = 612852475143;

	for ( ; prime < 12057; prime += 2)
	{
		while (n % prime == 0 && n != prime)
			n /= prime;
	}

	printf("%lu\n", n);
	return (0);
}
