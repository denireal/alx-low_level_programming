#include "main.h"

/**
* create_file - Create a file with specified permissions and content.
* @filename: The name of the file to create or truncate.
* @text_content: The text content to write to the file
* (NULL for an empty file).
*
* Return: 1 on success, -1 on failure.
*/
int create_file(const char *filename, char *text_content)
{
int fd;
ssize_t bytes_written;

if (!filename)
return (-1);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
if (fd == -1)
return (-1);

if (text_content)
{
bytes_written = write(fd, text_content, strlen(text_content));
if (bytes_written == -1)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
