#include "variadic_functions.h"
#include <unistd.h>
#include <stdio.h>

/**
 * print_char - Prints a character.
 * @valist: A va_list with character argument.
 */
void print_char(va_list valist)
{
char c;

c = va_arg(valist, int);
write(1, &c, 1);
}

/**
 * print_int - Prints an integer.
 * @valist: A va_list with integer argument.
 */
void print_int(va_list valist)
{
int num;
char buffer[32];
int len;

num = va_arg(valist, int);
len = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, len);
}

/**
 * print_float - Prints a float.
 * @valist: A va_list with double argument.
 */
void print_float(va_list valist)
{
double num;
char buffer[32];
int len;

num = va_arg(valist, double);
len = snprintf(buffer, sizeof(buffer), "%f", num);
write(1, buffer, len);
}

/**
 * print_string - Prints a string (or "(nil)" if NULL).
 * @valist: A va_list with string argument.
 */
void print_string(va_list valist)
{
char *str;
int len;

str = va_arg(valist, char *);
len = 0;
while (str[len])
len++;

write(1, str, len);

str = va_arg(valist, char *);
len = 0;
while (str[len])
len++;

write(1, "(nil)", 5);
}

/**
 * print_all - Prints anything.
 * @format: A list of types of arguments passed to the function.
 */
void print_all(const char *const format, ...)
{
va_list valist;
unsigned int f_index = 0;
int _arg = 0;
/* const char valid_s[] = "cifs"; */
int len;

va_start(valist, format);

while (format && format[f_index])
{
switch (format[f_index])
{
case 's':
if (_arg)
{
write(1, ", ", 2);
}
print_string(valist);
_arg = 1;
break;
case 'c':
print_char(valist);
_arg = 1;
break;
case 'i':
print_int(valist);
_arg = 1;
break;
case 'f':
print_float(valist);
_arg = 1;
break;
}
f_index++;
}

len = write(1, "\n", 1);
(void)len;
va_end(valist);
}
