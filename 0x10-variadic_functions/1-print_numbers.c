#include "variadic_functions.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_numbers - Print numbers separated by a separator
 * and end with a newline.
 * @separator: The string to be printed between numbers (can be NULL).
 * @n: The number of integers passed to the function.
 * @...: The integers to be printed.
 */

void print_numbers(const char *separator, const unsigned int n, ...)
{
va_list args;
unsigned int i;
char buffer[16];

va_start(args, n);

for (i = 0; i < n; i++)
{
int num = va_arg(args, int);

snprintf(buffer, sizeof(buffer), "%d", num);
write(STDOUT_FILENO, buffer, strlen(buffer));

if (separator != NULL && i < n - 1)
{
write(STDOUT_FILENO, separator, strlen(separator));
}
}

write(STDOUT_FILENO, "\n", 1);

va_end(args);
}
