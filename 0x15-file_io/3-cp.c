#include "main.h"

/**
* main - Copies the contents of a file to another file.
* @argc: The count of arguments provided to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description:
* If the argument count is incorrect, exit with code 97.
* If the source file does not exist or cannot be read
*			exit with code 98.
* If the destination file cannot be created or written to
*			exit with code 99.
* If either the destination or source file cannot be closed
*			exit with code 100.
*/

int main(int argc, char *argv[])
{
int src_fd, dest_fd;
ssize_t bytes_read, bytes_written;
char buffer[1024];

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

src_fd = open(argv[1], O_RDONLY);
if (src_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
exit(98);
}

dest_fd = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (dest_fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(src_fd);
exit(99);
}

while ((bytes_read = read(src_fd, buffer, 1024)) > 0)
{
if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
close(src_fd);
close(dest_fd);
exit(98);
}

bytes_written = write(dest_fd, buffer, bytes_read);
if (bytes_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
close(src_fd);
close(dest_fd);
exit(99);
}
}

if (close(src_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", src_fd);
exit(100);
}

if (close(dest_fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", dest_fd);
exit(100);
}

return (0);
}
