#include "main.h"

/**
* print_error_and_exit - Print an error message and exit with a
* specific code.
*
* @code: The exit code.
* @av: The arguments of the program.
* @fd: The current open file descriptor.
*/
void print_error_and_exit(int code, char **av, int fd)
{
switch (code)
{
case 97:
dprintf(STDERR_FILENO, "Usage: %s %s %s\n", av[0], "file_from", "file_to");
break;
case 98:
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
break;
case 99:
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
break;
case 100:
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
break;
default:
break;
}
exit(code);
}

/**
* main - The program's entry point.
*
* @ac: The arguments count.
* @av: The arguments values.
*
* Return: 0 on success, exit on failure.
*/
int main(int ac, char **av)
{
char buf[1024];
int source_fd = 0, target_fd = 0;
ssize_t bytes = 0, write_result = 0;

if (ac != 3)
print_error_and_exit(97, av, 0);

source_fd = open(av[1], O_RDONLY);
if (source_fd > -1 && av[1])
{
target_fd = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
if (target_fd > -1 && av[2])
{
while ((bytes = read(source_fd, buf, 1024)) != 0)
{
if (bytes == -1)
print_error_and_exit(98, av, 0);
write_result = write(target_fd, buf, bytes);
if (write_result == -1 || write_result != bytes)
print_error_and_exit(99, av, 0);
}
if (close(target_fd) == -1 || close(source_fd) == -1)
print_error_and_exit(100, av, (target_fd == -1) ? source_fd : target_fd);
return (0);
}
print_error_and_exit(99, av, 0);
}
print_error_and_exit(98, av, 0);
return (0);
}
