#include <stdio.h>
#include <unistd.h>

void first(void) __attribute__ ((constructor));

/**
 * first - Prints a message before the main function is executed
 *
 * Description: This function is executed automatically before the main
 * function is called. It writes a message to the standard output
 */
void first(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
