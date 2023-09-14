#include "variadic_functions.h"
#include <stdio.h>

/**
 * sum_them_all - Sums all its parameters.
 * @n: Number of parameters.
 * Return: Sum of all parameters.
*/
int sum_them_all(const unsigned int n, ...)
{

int sum;
unsigned int i;

va_list args;
va_start(args, n);

while (i < n)
{
sum += va_arg(args, int);
i++;
}

va_end(args);
return (sum);
}
