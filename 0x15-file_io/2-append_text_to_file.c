include "main.h"

/**
* append_text_to_file - Function that appends text to a file.
* @filename: The name of the file to append to.
* @text_content: The text content to append.
*
* Return: 1 on success, -1 on failure.
*/

int append_text_to_file(const char *filename, char *text_content)
{
int fd, bytes_appended, len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
{
while (text_content[len])
len++;
}

fd = open(filename, O_WRONLY | O_APPEND);

if (fd == -1)
return (-1);

bytes_appended = write(fd, text_content, len);

if (bytes_appended == -1)
{
close(fd);
return (-1);
}

close(fd);
return (1);
}
