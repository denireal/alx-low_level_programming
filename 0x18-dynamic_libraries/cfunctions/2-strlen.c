#include "main.h"
/**
*_strlen - program returns the length of a string
*@s: variable pointer character
*Return: string_len
*/
int _strlen(char *s)
{
	int string_len = 0;

	while (s[string_len] != '\0')
	{
		string_len++;
	}
	return (string_len);
}
