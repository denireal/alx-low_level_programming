#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - program entry point, performs a basic arithmetic operation
 * @argc: nos of command-line arguments.
 * @argv: array of command-line argument strings.
 * Return: 0 for success, other values for errors.
 */
int main(int argc, char *argv[])
{
int (*main_func)(int, int);

if (argc != 4)
{
printf("Error\n");
exit(98);
}

main_func = get_op_func(argv[2]);
if (main_func == NULL)
{
printf("Error\n");
exit(99);
}
printf("%d\n", main_func(atoi(argv[1]), atoi(argv[3])));
return (0);
}
