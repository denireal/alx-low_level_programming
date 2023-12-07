#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
* Main - function to generate a key based on the crackme5 username.
* @argc: Number of arguments passed to the program.
* @argv: Array of strings containing the arguments passed to the program.
* Return: Returns 0 on success, 1 on error.
*/
int main(int argc, char *argv[])
{
size_t index;
char *c = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
char key[7];
strcpy(key, "      ");

size_t username_len = strlen(argv[1]);
unsigned int sum = 0, product = 1;


if (argc != 2)
{
printf("Correct usage: ./keygen5 username\n");
return (1);
}

for (index = 0; index < username_len; index++)
{
sum += argv[1][index];
product *= argv[1][index];
}

key[0] = c[(username_len ^ 59) & 63];
key[1] = c[(sum ^ 79) & 63];
key[2] = c[(product ^ 85) & 63];

char max_char = argv[1][0];
for (index = 0; index < username_len; index++)
if (max_char <= argv[1][index])
max_char = argv[1][index];

srand(max_char ^ 14);
key[3] = c[rand() & 63];

unsigned int squared_sum = 0, rand_seed = 0;
for (index = 0; index < username_len; index++)
squared_sum += argv[1][index] * argv[1][index];

char loop_variable;
for (loop_variable = 0; loop_variable < argv[1][0]; loop_variable++)
rand_seed = rand();

key[4] = c[(squared_sum ^ 239) & 63];
key[5] = c[(rand_seed ^ 229) & 63];

printf("%s\n", key);
return (0);
}
