#include "main.h"
#include <stdio.h>

/**
 * main - program entry point
 *
 * Return: always 0 (sucess)
 */

int main(void)
{
	int i = 0;

	while (i < 100)
	{
		i++;
		if ((i % 3) != 0 && (i % 5) != 0)
		{
			printf("%d", i);
		}
		else if ((i % 3)  == 0 && (i % 5) != 0)
		{
			printf("Fizz");
		}
		else if ((i % 3) != 0 && (i % 5) == 0)
		{
			printf("Buzz");
		}
		else
		{
			printf("FizzBuzz");
		}
		if (i < 100)
			putchar(32);
	}
	putchar('\n');
	return (0);
}

