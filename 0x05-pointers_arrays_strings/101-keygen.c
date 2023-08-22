#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program to generates a random password.
 *
 * Return: Always 0 (Success).
 */

int main(void)
{
int password[100];
int sum = 0;
int diff;

srand(time(NULL));

for (int i = 0; i < 99; i++)
{
password[i] = rand() % 78;
sum += password[i];
putchar(password[i] + '0');
}

diff = 2772 - sum;
putchar(diff + '0');

return (0);
}
