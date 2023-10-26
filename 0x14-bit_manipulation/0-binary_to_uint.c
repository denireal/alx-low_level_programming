#include "main.h"

/**
* binary_to_uint - Converts a binary string to an unsigned integer.
* @b: Pointer to the binary string.
* Return: The converted unsigned integer.
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int val = 1, converted = 0;
size_t length;

if (b == NULL)
return (0);

for (length = 0; b[length] != '\0'; length++)
{
if (b[length] != '0' && b[length] != '1')
return (0);

if (b[length] == '1')
converted += val;

val *= 2;
}

return (converted);
}
