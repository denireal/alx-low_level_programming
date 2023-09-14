#include "variadic_functions.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

/**
 * print_all - function that prints anything.
 * @format: a list of types of arguments passed to the function.
 *
 * Return: no return available.
 */
void print_all(const char *const format, ...)
{
	va_list valist;
	va_start(valist, format);

	unsigned int f_index = 0;
	unsigned int s_index;
	int _arg = 0;
	char *str;
	const char valid_s[] = "cifs";

	while (format && format[f_index])
	{
		s_index = 0;

		while (valid_s[s_index])
		{
			if (format[f_index] == valid_s[s_index] && _arg)
			{
				write(1, ", ", 2);
				break;
			}
			s_index++;
		}
		switch (format[f_index])
		{
		case 'c':
		{
			char c = va_arg(valist, int);
			write(1, &c, 1);
			_arg = 1;
			break;
		}
		case 'i':
		{
			int num = va_arg(valist, int);
			char buffer[32];

			int len = snprintf(buffer, sizeof(buffer), "%d", num);
			write(1, buffer, len);
			_arg = 1;
			break;
		}
		case 'f':
		{
			double num = va_arg(valist, double);
			char buffer[32];
			int len = snprintf(buffer, sizeof(buffer), "%f", num);
			write(1, buffer, len);
			_arg = 1;
			break;
		}
		case 's':
		{
			str = va_arg(valist, char *);
			if (!str)
			{
				write(1, "(nil)", 5);
			}
			else
			{
				write(1, str, strlen(str));
			}
			_arg = 1;
			break;
		}
		}
		f_index++;
	}
	write(1, "\n", 1);
	va_end(valist);
}
