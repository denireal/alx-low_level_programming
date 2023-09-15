#include "variadic_functions.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * print_char - Prints a character.
 * @c: The character to print.
 */
void print_char(char c)
{
write(1, &c, 1);
}

/**
 * print_int - Prints an integer.
 * @num: The integer to print.
 */
void print_int(int num)
{
char buffer[32];
int len = snprintf(buffer, sizeof(buffer), "%d", num);

write(1, buffer, len);
}

/**
 * print_float - Prints a float.
 * @num: The double to print.
 */
void print_float(double num)
{
char buffer[32];
int len = snprintf(buffer, sizeof(buffer), "%f", num);

write(1, buffer, len);
}

/**
 * print_string - Prints a string (or "(nil)" if NULL).
 * @str: The string to print.
 */
void print_string(const char *str)
{
if (!str)
{
write(1, "(nil)", 5);
return;
}

write(1, str, strlen(str));
}

/**
 * print_all - Prints anything.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char *const format, ...)
{
va_list valist;
unsigned int f_index = 0;
int separator = 0;

va_start(valist, format);

while (format && format[f_index])
{
if (separator)
write(1, ", ", 2);

switch (format[f_index])
{
case 's':
print_string(va_arg(valist, const char *));
break;
case 'c':
print_char(va_arg(valist, int));
break;
case 'i':
print_int(va_arg(valist, int));
break;
case 'f':
print_float(va_arg(valist, double));
break;
}

separator = 1;
f_index++;
}

write(1, "\n", 1);
va_end(valist);
}
