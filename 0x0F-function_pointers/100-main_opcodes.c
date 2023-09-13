#include <stdlib.h>
#include <stdio.h>

/**
 * print_main_opcode - Prints the opcode of the print_main_opcode
 * function.
 * @bytes: Number of bytes to print.
 *
 * Return: nothing
 */
void print_opcodes(char *a, int n)
{
int i;

for (i = 0; i < n; i++)
{
printf("%.2hhx", a[i]);
if (i < n - 1)
printf(" ");
}
printf("\n");

}

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 or 2 on failure.
 */
int main(int argc, char **argv)
{
int n;

if (argc != 2)
{
printf("Error\n");
exit(1);
}
n = atoi(argv[1]);
if (n < 0)
{
printf("Error\n");
exit(2);
}
print_opcodes((char *)&main, n);
return (0);
}
