#include "main.h"

/**
* read_textfile - Reads a text file and writes it to the
* POSIX standard output.
* @filename: A pointer to the name of the file to be read.
* @letters: The number of characters to read and print.
*
* Return: On success, it returns the number of characters
* successfully read and printed. On failure, it returns 0.
*/

ssize_t read_textfile(const char *filename, size_t letters)
{
int file_descriptor, bytes_read, bytes_written;
char *buffer;

if (filename == NULL)
return (0);

file_descriptor = open(filename, O_RDONLY);
if (file_descriptor == -1)
return (0);

buffer = malloc(letters);
if (buffer == NULL)
{
close(file_descriptor);
return (0);
}

bytes_read = read(file_descriptor, buffer, letters);
if (bytes_read == -1)
{
close(file_descriptor);
free(buffer);
return (0);
}

bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
if (bytes_written == -1 || (size_t)bytes_written != letters)
{
close(file_descriptor);
free(buffer);
return (0);
}

close(file_descriptor);
free(buffer);
return (bytes_written);
}
