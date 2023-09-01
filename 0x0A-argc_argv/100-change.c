#include <stdio.h>
#include <stdlib.h>

#define QUARTER 25
#define DIME 10
#define NICKEL 5
#define PENNIES 2
#define PENNY 1

/**
 * main - prints the minimum number of coins to make change
 * for an amount of money.
 * @argc: representing number of command line arguments.
 * @argv: array of string that represent the command line arguments.
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	int nos_coins = 0, cents;

	if (argc == 1 || argc > 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);
	for (; cents > 0; nos_coins++)
	{
		if (cents >= QUARTER)
			cents -= QUARTER;
		else if (cents >= DIME)
			cents -= DIME;
		else if (cents >= NICKEL)
			cents -= NICKEL;
		else if (cents >= PENNIES)
			cents -= PENNIES;
		else if (cents >= PENNY)
			cents -= PENNY;
	}
	printf("%d\n", nos_coins);
	return (0);
}
