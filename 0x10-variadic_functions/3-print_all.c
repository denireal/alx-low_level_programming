#include "variadic_functions.h"
#include <stdio.h>

/**
* print_all - function that prints anything.
* @format: a list of arguments.
*/
void print_all(const char * const format, ...)
{
va_list args;
char *separator = "";
int i = 0;

va_start(args, format);
while (format && format[i])
{
switch (format[i])
{
case 'c':
printf("%s%c", separator, va_arg(args, int));
break;
case 'i':
printf("%s%d", separator, va_arg(args, int));
break;
case 'f':
printf("%s%f", separator, va_arg(args, double));
break;
case 's':
separator = va_arg(args, char *) ? "" : "(nil)";
printf("%s%s", separator, separator);
break;
default:
i++;
continue;
}
separator = ", ";
i++;
}
va_end(args);
printf("\n");
}
