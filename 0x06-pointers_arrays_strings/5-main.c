#include "main.h"
#include <stdio.h>

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	char s[] = "Holberton School!\n";
	char *p;
	char a[]="";
	char *t;
	p = string_toupper(s);
	printf("%s", p);
	printf("%s", s);

	t = string_toupper(a);
	printf("%s", t);
	printf("%s", a);
	return (0);
}
