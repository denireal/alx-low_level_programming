
/**
* string_toupper - program converts all lowercase letters
* of a string to uppercase.
* @s: The input string.
*
* Return: Pointer to the modified string.
*/

char *string_toupper(char *s)
{
	char *ptr = s;

	for (; *ptr; ++ptr)
	{
		if (*ptr >= 'a' && *ptr <= 'z')
		{
			*ptr -= 32;
		}
	}
	return (s);
}
