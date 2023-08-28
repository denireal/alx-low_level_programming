#include "main.h"
#include <stddef.h>
/**
* _strstr - Locates a substring within a string.
* @haystack: The string to search within.
* @needle: The substring to find.
*
* Return: If the substring is found, a pointer to the start
* of the located substring is returned. If not found, NULL is returned.
*/
char *_strstr(char *haystack, char *needle)
{
	if (*needle == '\0')
		return (haystack);
	

	while (*haystack)
	{
		char *haystack_ptr = haystack;
		char *needle_ptr = needle;

		while (*needle_ptr && *haystack_ptr == *needle_ptr)
		{
			haystack_ptr++;
			needle_ptr++;
		}

		if (*needle_ptr == '\0')
			return (haystack);
		haystack++;
	}
	return (NULL);
}
