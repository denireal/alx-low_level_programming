#include "main.h"

/**
* set_string - Updates the value of a pointer to a char.
* @s: Pointer to a pointer that will update the string.
* @to: Pointer to the string to be copied.
*
* Return: will retun void
*/

void set_string(char **s, char *to)
{
	*s = to;
}
