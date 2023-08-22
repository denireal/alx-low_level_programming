#include <stdio.h>
#include <stdlib.h>
#define SUM 2772
#include <time.h>

/**
 * main - program to generates a random password.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
	int sum = 0, i = 0, j = 0;
	char str[100];

	srand(time(NULL));
	while (sum < SUM)
	{
		if (SUM - sum < 48)
			sum -= str[--i];
		else if (SUM - sum <= 126)
			j = SUM - sum;
		else
			j = rand() % (126 - 48) + 48;
		if (j)
		{
			str[i++] = j;
			sum += j;
		}
		j = 0;
	}
	str[i] = '\0';
	printf("%s", str);
	return (0);
}
