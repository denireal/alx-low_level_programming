#include "main.h"

int _sqrt(int current_guess, int target_number);

/**
 * _sqrt_recursion - Returns the integer square root of a number
 * @n: The input number for which to find the square root
 *
 * Return: The integer square root of the number, or -1 for invalid input
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt(1, n));
}

/**
 * _sqrt - Recursively calculates the square root of a number
 * @current_guess: The current guess for the square root
 * @target_number: The number for which to find the square root
 *
 * Return: The square root if found, otherwise -1
 */
int _sqrt(int current_guess, int target_number)
{
	if (current_guess > target_number)
		return (-1);

	/* int squared_guess = current_guess * current_guess; */

	if (current_guess * current_guess == target_number)
		return (current_guess);

	return (_sqrt(current_guess + 1, target_number));
}
