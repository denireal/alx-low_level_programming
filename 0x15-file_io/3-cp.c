#include "main.h"

/**
* display_error_and_exit - Display an error message and exit.
* @error_code: The exit code to use.
* @format: The error message format.
*/
void display_error_and_exit(int error_code, const char *format, ...)
{
va_list args;
va_start(args, format);
vfprintf(stderr, format, args);
va_end(args);
exit(error_code);
}

/**
* copy_file - Copy the content of one file to another.
* @source_fd: Source file descriptor.
* @dest_fd: Destination file descriptor.
*/
void copy_file(int source_fd, int dest_fd)
{
char buffer[BUFSIZ];
ssize_t bytes_read, bytes_written;

while ((bytes_read = read(source_fd, buffer, BUFSIZ)) > 0)
{
bytes_written = write(dest_fd, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
display_error_and_exit(99, "Error: Can't write to file\n");
}
}

if (bytes_read == -1)
{
display_error_and_exit(98, "Error: Can't read from file\n");
}
}

/**
* main - Entry point of the program.
* @argc: Number of arguments.
* @argv: Arguments vector.
* Return: 0 on success, appropriate error code on failure.
*/
int main(int argc, char *argv[])
{
int source_fd, dest_fd;

if (argc != 3)
{
display_error_and_exit(97, "Usage: cp file_from file_to\n");
}

source_fd = open(argv[1], O_RDONLY);
if (source_fd == -1)
{
display_error_and_exit(98, "Error: Can't read from file %s\n", argv[1]);
}

dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (dest_fd == -1)
{
display_error_and_exit(99, "Error: Can't write to file %s\n", argv[2]);
}

copy_file(source_fd, dest_fd);

if (close(source_fd) == -1 || close(dest_fd) == -1)
{
display_error_and_exit(100, "Error: Can't close file descriptors\n");
}

return (0);
}
