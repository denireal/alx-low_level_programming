#include "main.h"

#define BUFSIZE 1024

int copy_file(const char *from, const char *to);

/**
* main - Copies the content of a file to another file.
* @argc: The number of arguments.
* @argv: The array of argument strings.
*
* Return: 0 on success, or the appropriate exit code on failure.
*/
int main(int argc, char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
return (97);
}

if (copy_file(argv[1], argv[2]) == -1)
{
return (98);
}

return (0);
}

/**
* copy_file - Copies the content of one file to another.
* @from: The name of the source file.
* @to: The name of the destination file.
*
* Return: 0 on success, -1 on failure.
*/
int copy_file(const char *from, const char *to)
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFSIZE];

fd_from = open(from, O_RDONLY);
if (fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
return (-1);
}

fd_to = open(to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
close(fd_from);
return (-1);
}

while ((bytes_read = read(fd_from, buffer, BUFSIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", to);
close(fd_from);
close(fd_to);
return (-1);
}
}

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", from);
close(fd_from);
close(fd_to);
return (-1);
}

if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
return (-1);
}

if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
return (-1);
}

return (0);
}
