#include "main.h"

/**
* rot13 - function encodes a string
* @s: the input string
*
* Return: returns an encoded string
*/

char *rot13(char *s)
{
int first_index = 0, sec_index = 0;

static char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
static char rot13_table[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

for (; s[first_index]; first_index++)
{
for (; sec_index < 52; sec_index++)
{
if (s[first_index] == alphabet[sec_index])
{
s[first_index] = rot13_table[sec_index];
break;
}
}

return (s);
}
