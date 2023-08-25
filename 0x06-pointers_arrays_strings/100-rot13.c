#include "main.h"

/**
* rot13 - function encodes a string
* @s: the input string
*
* Return: returns an encoded string
*/

char *rot13(char *s)
{
char *ptr = s;
char rot13_table[256];

int i = 0;
char c = 'a';

for (; i < 256; i++)
{
rot13_table[i] = i;
}

for (; c <= 'z'; c++)
{
rot13_table[c] = 'a' + (c - 'a' + 13) % 26;
rot13_table[c - 'a' + 'A'] = rot13_table[c] - 'a' + 'A';
}

while (*s)
{
*s = rot13_table[*s];
s++;
}

return (ptr);
}
