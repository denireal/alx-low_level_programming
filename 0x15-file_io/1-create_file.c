#include "main.h"

/**
* create_file - Function that create a file and write text into it.
* @filename: The name of the file to be created.
* @text_content: The text content to write into the file.
*
* Return: 1 on success, -1 on failure.
*/

int create_file(const char *filename, char *text_content)
{
int fd, bytes_written, text_length, close_status;

if (filename == NULL)
return (-1);

fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0600);
if (fd == -1)
return (-1);

if (text_content == NULL)
text_length = 0;
else
{
for (text_length = 0; text_content[text_length] != '\0'; text_length++)
;

bytes_written = write(fd, text_content, text_length);
if (bytes_written == -1)
return (-1);
}

close_status = close(fd);
if (close_status == -1)
return (-1);

return (1);
}
