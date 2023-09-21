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
	char message1[] = "You're beat! and yet, you must allow,\n";
	char message2[] = "I bear my house upon my back!\n";
	size_t len1 = sizeof(message1) - 1;
	size_t len2 = sizeof(message2) - 1;

	write(STDOUT_FILENO, message1, len1);
	write(STDOUT_FILENO, message2, len2);
}
