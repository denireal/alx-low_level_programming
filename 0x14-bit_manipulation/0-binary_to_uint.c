#include "main.h"
#include <stddef.h> /* for NULL definition */

/**
* binary_to_uint - Converts a binary number to an unsigned int.
* @b: A pointer to a string containing '0' and '1' characters.
*
* Return: The converted number, or 0 if there are invalid characters
* in the string or if b is NULL.
*/
unsigned int binary_to_uint(const char *b)
{
int i = 0;
unsigned int result = 0;

if (b == NULL)
return (0);

for (; b[i] != '\0'; i++)
{
if (b[i] == '0' || b[i] == '1')
{
result = result * 2 + (b[i] - '0');
}
else
{
return (0); /* Return 0 if an invalid character is encountered. */
}
}

return (result);
}
