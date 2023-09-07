#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

void check_if_zero(char *argv[]);
char *init_result_array(int length);
int validate_and_calculate_length(char *argv[], int num);
void multiply_numbers(char *argv[], char *res, int len1, int len2);
/**
 * main - Entry point.
 * @argv: Argument vector containing the numbers to check.
 * @argc: Argument count
 *
 * Return: 0.
 */
int main(int argc, char *argv[])
{
	int len1;
	int len2;
	int len_res;
	char *res;

	if (argc != 3)
	{
		fprintf(stderr, "Error\n");
		return (98);
	}

	check_if_zero(argv);

	len1 = validate_and_calculate_length(argv, 1);
	len2 = validate_and_calculate_length(argv, 2);

	len_res = len1 + len2;
	res = init_result_array(len_res);

	multiply_numbers(argv, res, len1, len2);

	printf("%s\n", res);

	free(res);
	return (0);
}
/**
 * check_if_zero - Check if the provided numbers are both zero.
 * @argv: Argument vector containing the numbers to check.
 *
 * This function checks if both numbers provided as command-line
 * arguments are zero.
 * Return: If both numbers are zero, it prints "0" and
 * exits the program.
 */
void check_if_zero(char *argv[])
{
	int i;
	int first_zero = 1, second_zero = 1;

	for (i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] != '0')
		{
			first_zero = 0;
			break;
		}
	}

	for (i = 0; argv[2][i]; i++)
	{
		if (argv[2][i] != '0')
		{
			second_zero = 0;
			break;
		}
	}

	if (first_zero || second_zero)
	{
		printf("0\n");
		exit(0);
	}
}
/**
 * init_result_array - Initialize an array with zeros.
 * @length: Length of the array to initialize.
 *
 * This function initializes a character array of the
 * specified length with zeros
 * Return: returns a pointer to the newly allocated array.
 */
char *init_result_array(int length)
{
	char *res;
	int i;

	res = (char *)malloc((length + 1) * sizeof(char));

	if (res == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		exit(98);
	}

	for (i = 0; i < length; i++)
	{
		res[i] = '0';
	}

	res[length] = '\0';
	return (res);
}
/**
 * validate_and_calculate_length - Validate a number and calculate
 * its length.
 * @argv: Argument vector containing the number to validate.
 * @num: Index of the number in the argument vector.
 *
 * This function validates a number by checking if it consists of
 * digits (0-9) only.
 * Return: returns the length of the number.
 */
int validate_and_calculate_length(char *argv[], int num)
{
	int len = 0;
	int i;

	for (i = 0; argv[num][i]; i++)
	{
		if (!isdigit(argv[num][i]))
		{
			fprintf(stderr, "Error\n");
			exit(98);
		}
		len++;
	}

	return (len);
}
/**
 * multiply_numbers - Multiply two numbers represented as strings.
 * @argv: Argument vector containing the two numbers to multiply.
 * @res: Pointer to the result array to store the product.
 * @len1: Length of the first number.
 * @len2: Length of the second number.
 *
 * This function multiplies two numbers represented as strings
 * and stores the result
 * in the provided result array. It uses the lengths of the numbers
 * to perform the multiplication and handle carry operations.
 *
 * Return: void
 */
void multiply_numbers(char *argv[], char *res, int len1, int len2)
{
	int carry = 0;
	int res_index = len1 + len2 - 1;
	int i = len1 - 1, j = len2 - 1;
	int digit1, digit2, product;

	while (res_index >= 0)
	{
		digit1 = (i >= 0) ? (argv[1][i] - '0') : 0;
		digit2 = (j >= 0) ? (argv[2][j] - '0') : 0;
		product = (digit1 * digit2) + (res[res_index] - '0') + carry;

		carry = product / 10;
		res[res_index] = (product % 10) + '0';

		res_index--;
		i--;
		j--;

		if (j < 0)
		{
			if (res[0] != '0')
			{
				break;
			}
			len1--;
			res_index--;
			res = (char *)realloc(res, (len1 + len2 + 1) * sizeof(char));
			res[len1 + len2] = '\0';
			i = len1 - 1;
			j = len2 - 1;
			carry = 0;
		}
	}
}
