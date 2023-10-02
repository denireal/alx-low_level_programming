#include "main.h"

/**
* error_file - Checks whether files can be opened.
* @file_from: File descriptor for source file.
* @file_to: File descriptor for destination file.
* @argv: The arguments vector.
*
* Return: 0 on success, 98 or 99 on failure.
*/
int error_file(int file_from, int file_to, char *argv[])
{
if (file_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
return (98);
}
if (file_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
return (99);
}
return (0);
}

/**
* copy_file - Copies the contents of one file to another.
* @src_fd: Source file descriptor.
* @dest_fd: Destination file descriptor.
* @argv: Arguments vector.
*
* Return: 0 on success, -1 on failure.
*/
int copy_file(int src_fd, int dest_fd, char *argv[])
{
ssize_t nchars, nwr;
char buf[1024];

while ((nchars = read(src_fd, buf, sizeof(buf))) > 0)
{
nwr = write(dest_fd, buf, nchars);
if (nwr == -1)
return (-1);
}

if (nchars == -1)
return (-1);

return (0);
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
int file_from, file_to, err_close;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
return (97);
}

file_from = open(argv[1], O_RDONLY);
file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);

int error_code = error_file(file_from, file_to, argv);
if (error_code != 0)
return (error_code);

if (copy_file(file_from, file_to, argv) == -1)
{
err_close = close(file_from);
if (err_close == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);

err_close = close(file_to);
if (err_close == -1)
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
return (99);
}
err_close = close(file_from);
if (err_close == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_from);
return (100);
}
err_close = close(file_to);
if (err_close == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_to);
return (100);
}
return (0);
}
