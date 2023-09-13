#include "3-calc.h"

/**
 * main - program entry point, performs a basic arithmetic operation
 * @argc: nos of command-line arguments.
 * @argv: array of command-line argument strings.
 * Return: 0 for success, other values for errors.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;
	char *operator;

	if (argc != 4)
	{
		fprintf(stderr, "Error\n");
		return (argc != 4 ? 98 : 0);
	}

	operator = argv[2];

	if (strcmp(operator, "+") != 0 &&
			strcmp(operator, "-") != 0 &&
			strcmp(operator, "*") != 0 &&
			strcmp(operator, "/") != 0 &&
			strcmp(operator, "%") != 0)
	{
		fprintf(stderr, "Error\n");
		return (99);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[3]);

	if ((*operator == '/' || *operator == '%') && num2 == 0)
	{
		fprintf(stderr, "Error\n");
		return (100);
	}

	result = (*get_op_func(operator))(num1, num2);
	printf("%d\n", result);

	return (0);
}
