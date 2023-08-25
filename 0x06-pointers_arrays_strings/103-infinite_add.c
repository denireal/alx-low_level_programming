#include "main.h"
#include <string.h>
/**
* infinite_add -  program adds two numbers
* @n1: first number
* @n2: second number
* @r: returned result
* @size_r: length of r
*
* Return: will return sum
*/

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
int len_n1 = strlen(n1);
int len_n2 = strlen(n2);
int carry = 0;
int result_index = size_r - 1;
int n1_index = len_n1 - 1;
int n2_index = len_n2 - 1;

if (len_n1 + len_n2 + 1 > size_r)
return (0);

r[result_index] = '\0';

while (n1_index >= 0 || n2_index >= 0 || carry)
{
if (n1_index >= 0)
carry += n1[n1_index--] - '0';

if (n2_index >= 0)
carry += n2[n2_index--] - '0';

r[--result_index] = (carry % 10) + '0';
carry /= 10;
}

return (r + result_index);
}
