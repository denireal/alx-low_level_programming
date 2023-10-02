#include "main.h"

/**
* main - Performs the task of copying one file's content to another.
* @argc: Number of arguments provided when running the program.
* @argv: Array storing the command-line arguments.
*
* Return: Returns 0 upon successful execution, or
* error codes 97, 98, 99, or 100 on failure.
*/
int main(int argc, char *argv[])
{
int source_fd, dest_fd;
ssize_t bytes_read, bytes_written;
char buffer[BUFSIZ];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
return (97);
}

source_fd = open(argv[1], O_RDONLY);
if (source_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
return (98);
}

dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(source_fd);
return (99);
}

while ((bytes_read = read(source_fd, buffer, BUFSIZ)) > 0)
{
bytes_written = write(dest_fd, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(source_fd);
close(dest_fd);
return (99);
}
}

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(source_fd);
close(dest_fd);
return (98);
}

if (close(source_fd) == -1 || close(dest_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close file descriptors\n");
return (100);
}

return (0);
}
