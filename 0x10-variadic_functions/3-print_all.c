#include "variadic_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * print_char - Prints a character
 * @arg: A character argument
 */
void print_char(va_list arg)
{
char c = va_arg(arg, int);

write(1, &c, 1);
}

/**
 * print_int - Prints an integer
 * @arg: An integer argument
 */
void print_int(va_list arg)
{
int num;
char buffer[32];

num = va_arg(arg, int);
snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, strlen(buffer));
}

/**
 * print_float - Prints a float
 * @arg: A double argument
 */
void print_float(va_list arg)
{
double num = va_arg(arg, double);
char buffer[32];

snprintf(buffer, sizeof(buffer), "%f", num);
write(1, buffer, strlen(buffer));
}

/**
 * print_string - Prints a string (or "(nil)" if NULL)
 * @arg: A string argument
 */
void print_string(va_list arg)
{
char *s = va_arg(arg, char *);
char *output = s ? s : "(nil)";

write(1, output, strlen(output));
}

/**
 * print_all - Prints various types of data based on a format string
 * @format: A string containing format specifiers
 * @...: Variable number of arguments corresponding to the
 * format specifiers
 *
 * Description: This function prints data of different types based
 * on the format
 * string. The format string can contain the following specifiers:
 *   - 'c' for char
 *   - 'i' for integer
 *   - 'f' for float
 *   - 's' for string (if the string is NULL, "(nil)" is printed)
 *   - Any other character is ignored
 */
void print_all(const char *const format, ...)
{
char newline = '\n';
char separator[3] = {0};
const char *format_ptr = format;

va_list args;
va_start(args, format);

while (*format_ptr)
{
char ch = *format_ptr;

switch (ch)
{
case 'c':
snprintf(separator, sizeof(separator), "%s", ", ");
print_char(args);
break;
case 'i':
snprintf(separator, sizeof(separator), "%s", ", ");
print_int(args);
break;
case 'f':
snprintf(separator, sizeof(separator), "%s", ", ");
print_float(args);
break;
case 's':
snprintf(separator, sizeof(separator), "%s", ", ");
print_string(args);
break;
}

if (separator[0] != '\0')
{
write(1, separator, strlen(separator));
}

format_ptr++;
}

va_end(args);

write(1, &newline, 1);
}
