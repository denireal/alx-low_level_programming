#include <stdio.h>
#include "main.h"

/**
 * read_textfile - Reads and prints the content of a text file.
 * @filename: The name of the file to read.
 * @letters: The number of letters to read and print.
 *
 * Return: The actual number of letters read and printed.
 * 0 on failure or if filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
char *buffer;

if (filename == NULL)
return (0);  /* If filename is NULL, return 0 as specified. */

FILE *file;
file = fopen(filename, "r");
if (file == NULL)
return (0);  /* If the file can't be opened, return 0. */


buffer = (char *)malloc(sizeof(char) * letters);
if (buffer == NULL)
{
fclose(file);
return (0);  /* Allocation failed; return 0. */
}

ssize_t bytesRead;
bytesRead = fread(buffer, sizeof(char), letters, file);
if (bytesRead <= 0)
{
free(buffer);
fclose(file);
return (0);  /* Reading failed; return 0. */
}

ssize_t bytesWritten;
bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);
if (bytesWritten != bytesRead)
{
free(buffer);
fclose(file);
return (0);  /* Writing failed; return 0. */
}

free(buffer);
fclose(file);
return (bytesRead);
}
