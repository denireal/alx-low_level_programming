#include "main.h"

/**
* binary_to_uint - Converts a binary string to an unsigned integer.
* @b: Pointer to the binary string.
* Return: The converted unsigned integer.
*/
unsigned int binary_to_uint(const char *b)
{
unsigned int result = 0, multiplier = 1;
int length = 0;

if (b == NULL)
return (0);

while (b[length] != '\0')
{
if (b[length] != '0' && b[length] != '1')
return (0);

length++;
}

while (length > 0)
{
length--;
result += (b[length] - '0') * multiplier;
multiplier *= 2;
}

return (result);
}
