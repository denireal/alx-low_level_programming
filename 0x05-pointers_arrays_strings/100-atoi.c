#include <stdio.h>

/**
 * _atoi - program converts a given string to integer
 * @s: input string to be processed
 *
 * Return: b is returned
 */
int _atoi(char *s)
{
	int a = 1;
	unsigned int b = 0;
	char c = 0;

	while (*s)
	{
		if (*s == '-')
			a *= -1;

		if (*s >= '0' && *s <= '9')
		{
			c = 1;
			b = b * 10 + *s - '0';
		}

		else if (c)
			break;
		s++;
	}

	if (a < 0)
		b = (-b);

	return (b);
}
