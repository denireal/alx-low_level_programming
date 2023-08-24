#include "main.h"

/**
* string_toupper - program converts all lowercase letters
* of a string to uppercase.
* @str: The input string.
*
* Return: Pointer to the modified string.
*/
char *string_toupper(char *str)
{
char *a_ptr = str;

while (*a_ptr)
{
*a_ptr = toupper(*a_ptr);
a_ptr++;
}

return (str);
}
