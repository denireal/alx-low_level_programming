#include "main.h"

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: The name of the file to which text is added.
* @text_content: The content to append to the file.
*
* Return: Returns 1 upon success, and -1 if there is a failure
* (such as the file not existing or a write error).
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd, num_chars_written, file_status;

if (!filename)
return (-1);

fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

if (!text_content)
{
close(fd);
return (1);
}

num_chars_written = 0;
while (text_content[num_chars_written])
num_chars_written++;

file_status = write(fd, text_content, num_chars_written);
close(fd);

return (file_status == -1 ? -1 : 1);
}
