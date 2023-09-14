#include "variadic_functions.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/**
 * print_char - Prints a character
 * @arg: A character argument
 */
void print_char(va_list arg) {
    char c = va_arg(arg, int);
    write(1, &c, 1);
}

/**
 * print_int - Prints an integer
 * @arg: An integer argument
 */
void print_int(va_list arg) {
    int num = va_arg(arg, int);
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%d", num);
    write(1, buffer, strlen(buffer));
}

/**
 * print_float - Prints a float
 * @arg: A double argument
 */
void print_float(va_list arg) {
    double num = va_arg(arg, double);
    char buffer[32];
    snprintf(buffer, sizeof(buffer), "%f", num);
    write(1, buffer, strlen(buffer));
}

/**
 * print_string - Prints a string (or "(nil)" if NULL)
 * @arg: A string argument
 */
void print_string(va_list arg) {
    char *s = va_arg(arg, char *);
    char *output = s ? s : "(nil)";
    write(1, output, strlen(output));
}

/**
 * print_all - Prints various types of data based on a format string
 * @format: A string containing format specifiers
 * @...: Variable number of arguments corresponding to the format specifiers
 *
 * Description: This function prints data of different types based on the format
 * string. The format string can contain the following specifiers:
 *   - 'c' for char
 *   - 'i' for integer
 *   - 'f' for float
 *   - 's' for string (if the string is NULL, "(nil)" is printed)
 *   - Any other character is ignored
 */
void print_all(const char *const format, ...) {
    va_list args;
    va_start(args, format);

    char ch;
    const char *fmt = format;

    int first_output = 1; // To control comma and space placement
    char newline = '\n';

    while ((ch = *fmt)) {
        if (!first_output) {
            write(1, ", ", 2);
        }
        
        switch (ch) {
            case 'c':
                print_char(args);
                break;
            case 'i':
                print_int(args);
                break;
            case 'f':
                print_float(args);
                break;
            case 's':
                print_string(args);
                break;
        }
        
        first_output = 0; // Set to 0 after the first value is printed
        fmt++;
    }

    va_end(args);

    write(1, &newline, 1); // Print a newline character
}
