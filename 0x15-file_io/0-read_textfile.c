#include "main.h"

/**
* read_textfile - Reads and prints the content of a text file.
* @filename: The name of the file to read.
* @letters: The number of letters to read and print.
*
* Return: The actual number of letters read and printed.
* 0 on failure or if filename is NULL.
*/
ssize_t read_textfile(const char *filename, size_t letters)
{
int file_descriptor;
ssize_t bytes_read, bytes_written;
char *read_buffer;

if (filename == NULL)
return (0);  /* If filename is NULL, return 0 as specified. */

file_descriptor = open(filename, O_RDONLY);

if (file_descriptor == -1)
return (0);  /* If opening the file fails, return 0. */

read_buffer = malloc(sizeof(char) * letters);
if (!read_buffer)
{
close(file_descriptor);
return (0);  /* If memory allocation fails, return 0. */
}

bytes_read = read(file_descriptor, read_buffer, letters);
bytes_written = write(STDOUT_FILENO, read_buffer, bytes_read);

close(file_descriptor);

free(read_buffer);

return (bytes_written);
}
