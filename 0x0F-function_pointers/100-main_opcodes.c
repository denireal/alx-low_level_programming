#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point.
 * @argc: Argument count.
 * @argv: Array of arguments.
 *
 * Return: 0 on success, 1 or 2 on failure.
 */
int main(int argc, char *argv[])
{
        int i, bytes;
        unsigned char *mainfunc_ptr;

        if (argc != 2)
        {
                printf("Error\n");
                exit(1);
        }
        bytes = atoi(argv[1]);
        if (bytes < 0)
        {
                printf("Error\n");
                exit(2);
        }
        mainfunc_ptr = (unsigned char *)main;
        i = 0;
        if (bytes > 0)
        {
                while (i < (bytes - 1))
                        printf("%02hhx ", mainfunc_ptr[i++]);
                printf("%hhx\n", mainfunc_ptr[i]);
        }
        return (0);
}
