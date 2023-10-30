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
int file_desc, num_letters, write_result;

if (!filename)
return (-1);

file_desc = open(filename, O_WRONLY | O_APPEND);

if (file_desc == -1)
return (-1);

if (text_content)
{
for (num_letters = 0; text_content[num_letters]; num_letters++)
;

write_result = write(file_desc, text_content, num_letters);

if (write_result == -1)
{
close(file_desc);
return (-1);
}
}

if (close(file_desc) == -1)
return (-1);

return (1);
}
