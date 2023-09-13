#include "function_pointers.h"

/**
 * print_name - function that prints a name
 * @name: variable representing name of the person
 * @f: this is a pointer
**/

void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
	{
		return;
	}
	else
	{
		f(name);
	}
}
