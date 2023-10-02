#include "main.h"

/**
* copy_file - Copies the content of one file to another.
* @src_fd: Source file descriptor.
* @dest_fd: Destination file descriptor.
*
* Return: 0 on success, -1 on failure.
*/
int copy_file(int src_fd, int dest_fd)
{
ssize_t bytes_read, bytes_written;
char buffer[BUFSIZ];

while ((bytes_read = read(src_fd, buffer, BUFSIZ)) > 0)
{
bytes_written = write(dest_fd, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
return (-1); /* Copying error */
}

return ((bytes_read == 0) ? 0 : -1);
}

/**
* main - Entry point of the program.
* @argc: Number of arguments.
* @argv: Arguments vector.
*
* Return: 0 on success, 97, 98, 99, or 100 on failure.
*/
int main(int argc, char *argv[])
{
int source_fd, dest_fd, close_result;
int exit_code = 0;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
return (97); /* Invalid arguments */
}

source_fd = open(argv[1], O_RDONLY);
if (source_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
return (98); /* Read error */
}

dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(source_fd);
return (99); /* Write error */
}

if (copy_file(source_fd, dest_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't copy file\n");
close_result = -1;
}
else
close_result = 0;

if (close(source_fd) == -1 || close(dest_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
exit_code = 100;
}

return ((close_result == 0) ? exit_code : 99);
}
