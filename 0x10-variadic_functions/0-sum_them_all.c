include <stdio.h>
#include <stdarg.h>

/**
 * sum_them_all - Sums all its parameters.
 * @n: Number of parameters.
 * Return: Sum of all parameters.
*/
int sum_them_all(const unsigned int n, ...)
{
va_list args;va_start(args, n);
int sum = 0;
unsigned int i = 0;

while (i < n)
{
sum += va_arg(args, int);
i++;
}

va_end(args);
return (sum);
}
