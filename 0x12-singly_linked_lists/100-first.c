#include <stdio.h>
#include <unistd.h>

void first(void) __attribute__ ((constructor));

/**
 * first - Prints a message before the main function is executed
 *
 * Description: This function is executed automatically before the main
 * function is called. It writes a message to the standard output using the
 * write system call.
 */
void first(void)
{
	int i = 0;

	char message[] = "You're beat! and yet, you must allow,\n"
	                 "I bear my house upon my back!\n";

	for (; message[i] != '\0'; i++) {
		putchar(message[i]);
	}
}
