#include <stdio.h>

/**
 * main - Program entry point
 * description - Program that prints all single digit numbers of base 10
 * starting from 0, followed by a new line
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned int base_ten_num = 0;

	while (base_ten_num < 10)
	{
		printf("%u", base_ten_num);
		base_ten_num++;
	}
	putchar('\n');

	return (0);
}
