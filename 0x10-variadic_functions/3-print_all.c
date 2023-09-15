#include "variadic_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * print_all - function that prints anything.
 * @format: a list of arguments.
 *
 * Return: no return available.
 */
void print_all(const char * const format, ...)
{
va_list valist;
unsigned int a = 0, b, c = 0;
char *str;
const char _arg[] = "cifs";

va_start(valist, format);
while (format && format[a])
{
b = 0;
while (_arg[b])
{
if (format[a] == _arg[b] && c)
{
write(1, ", ", 2);
break;
}
b++;
}
switch (format[a])
{
case 'c':
{
char ch = va_arg(valist, int);
write(1, &ch, 1);
c = 1;
break;
}
case 'i':
{
int num = va_arg(valist, int);
char buffer[32];
int len = snprintf(buffer, sizeof(buffer), "%d", num);
write(1, buffer, len);
c = 1;
break;
}
case 'f':
{
double num = va_arg(valist, double);
char buffer[32];
int len = snprintf(buffer, sizeof(buffer), "%f", num);

write(1, buffer, len);
c = 1;
break;
}
case 's':
str = va_arg(valist, char *);
c = 1;
if (!str)
{
write(1, "(nil)", 5);
break;
}
write(1, str, strlen(str));
break;
}
a++;
}
write(1, "\n", 1);
va_end(valist);
}
