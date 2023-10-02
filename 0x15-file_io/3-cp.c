#include "main.h"

#define BUFSIZE 1024

/**
* close_fd - Close a file descriptor and display an
* error message if it fails.
* @fd: The file descriptor to be closed.
*
* Returns: 0 on success, -1 on failure.
*/
int close_fd(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to close file descriptor %d\n", fd);
return (-1);
}
return (0);
}

/**
* copy_file - Copy the contents from one file to another.
* @src_filename: The name of the source file.
* @dest_filename: The name of the destination file.
*
* Returns: 0 on success, 97, 98, or 99 on error.
*/
int copy_file(const char *src_filename, const char *dest_filename)
{
int fd_src, fd_dest;
ssize_t bytes_read;
char buffer[BUFSIZE];

fd_src = open(src_filename, O_RDONLY);
if (fd_src == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to read from the file %s\n", src_filename);
return (98);
}

fd_dest = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (fd_dest == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", dest_filename);
close_fd(fd_src);
return (99);
}

while ((bytes_read = read(fd_src, buffer, BUFSIZE)) > 0)
{
if (write(fd_dest, buffer, bytes_read) == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to write to %s\n", dest_filename);
close_fd(fd_src);
close_fd(fd_dest);
return (99);
}
}

close_fd(fd_src);
close_fd(fd_dest);

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Unable to read from the file %s\n", src_filename);
return (98);
}

return (0);
}

/**
* main - The program's entry point.
* @argc: The number of command-line arguments.
* @argv: The array of command-line arguments.
*
* Returns: 0 on success, 97, 98, or 99 on error.
*/
int main(int argc, const char *argv[])
{
if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp source_file destination_file\n");
return (97);
}

if (copy_file(argv[1], argv[2]) != 0)
return (97);

return (0);
}
