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
/* Declarations */
size_t index;
char *charset = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";
char key[7];
size_t username_len;
unsigned int sum, product;
char max_char;
unsigned int squared_sum, rand_seed;
char loop_variable;

/* Initialization */
strcpy(key, "      ");


if (argc != 2)
{
printf("Correct usage: ./keygen5 username\n");
return 1; /* Exit with an error code */
}


username_len = strlen(argv[1]);
sum = 0;
product = 1;

for (index = 0; index < username_len; index++)
{
sum += argv[1][index];
product *= argv[1][index];
}


key[0] = charset[(username_len ^ 59) & 63];
key[1] = charset[(sum ^ 79) & 63];
key[2] = charset[(product ^ 85) & 63];


max_char = argv[1][0];
for (index = 0; index < username_len; index++)
if (max_char <= argv[1][index])
max_char = argv[1][index];


srand(max_char ^ 14);
key[3] = charset[rand() & 63];

squared_sum = 0;
rand_seed = 0;

for (index = 0; index < username_len; index++)
squared_sum += argv[1][index] * argv[1][index];

for (loop_variable = 0; loop_variable < argv[1][0]; loop_variable++)
rand_seed = rand();


key[4] = charset[(squared_sum ^ 239) & 63];
key[5] = charset[(rand_seed ^ 229) & 63];


printf("%s\n", key);
return (0);
}
