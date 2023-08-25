#include "main.h"
#include <stdbool.h>
#include <ctype.h>

/**
 * cap_string - function capitalizes all words of a string.
 * @str: The input string to be capitalized.
 *
 * Return: Return the string str.
 */
char *cap_string(char *str)
{
bool new_word = true;

int index = 0;

for (; str[index] != '\0'; index++)
{
if (isalpha(str[index]))
{
if (new_word)
{
str[index] = toupper(str[index]);
new_word = false;
}
}
else if (isspace(str[index]) || ispunct(str[index]))
{
new_word = true;
}
}

return (str);
}
