#include <stdio.h>
#define LARGEST 10000000000

/**
 * main - Program entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	unsigned long int front_digit_1 = 0, back_digit_1 = 1;
	unsigned long int front_digit_2 = 0, back_digit_2 = 2;
	unsigned long int a, b, c;
	int count;

	printf("%lu, %lu, ", back_digit_1, back_digit_2);
	for (count = 2; count < 98; count++)
	{
		if (back_digit_1 + back_digit_2 > LARGEST || front_digit_2 > 0 || front_digit_1 > 0)
		{
			a = (back_digit_1 + back_digit_2) / LARGEST;
			b = (back_digit_1 + back_digit_2) % LARGEST;
			c = front_digit_1 + front_digit_2 + a;
			front_digit_1 = front_digit_2;
			front_digit_2 = c;
			back_digit_1 = back_digit_2;
			back_digit_2 = b;

			printf("%lu%010lu", front_digit_2, back_digit_2);
		}
		else
		{
			b = back_digit_1 + back_digit_2;
			back_digit_1 = back_digit_2;
			back_digit_2 = b;

			printf("%lu", back_digit_2);
		}
		if (count != 97)
			printf(", ");
	}
	printf("\n");
	return (0);
}
