#include <stdio.h>

/**
 * main - program entry point
 *
 * Return: always 0 (sucess)
 */

int main(void)
{
	long int prime = 3, num = 612852475143;

	for ( ; prime < num / 2; prime += 2)
	{
		if ((num % prime) == 0)
		{
			if ((prime % 3) == 2)
			{
				printf(",%lu ", prime);
			}

			prime += 2;
		}
	}
	putchar('\n');
	return (0);
}
