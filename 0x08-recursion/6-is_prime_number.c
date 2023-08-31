#include "main.h"

/**
 * is_divisible - checks if num is divisible by a divisor
 * @num: the number to be checked
 * @div: the current divisor being checked
 *
 * Return: if num is divisible return 0, otherwise return 1
 */
int is_divisible(int num, int div)
{
	if (div * div > num)
		return (1);

	if (num % div == 0)
		return (0);

	return (is_divisible(num, div + 1));
}

/**
 * is_prime_number - checks if a number is prime
 * @n: an input integer to be checked
 *
 * Return: if n is prime return 0,otherwise return 1
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	if (n <= 3)
		return (1);

	return (is_divisible(n, 2));
}
