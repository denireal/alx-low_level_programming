#include <string.h>

/**
* leet - function to encode a string
* @s: an input string to encode
*
* Return: returns the encoded string
*/
char *leet(char *s)
{
char *dictionary = "aAeEoOtTlL";
char *substitute = "4433007711";
int i = 0;

for (; s[i]; i++)
{
char *found = strchr(dictionary, s[i]);
if (found)
{
s[i] = substitute[found - dictionary];
}
}
return (s);
}
