#include <stdio.h>
#include <unistd.h>
#include "lists.h"

/**
* print_list - function that prints all the elements
* of a linked list
* @h: pointer to the list_t list to print
*
* Return: the number of nodes printed
*/
size_t print_list(const list_t *h)
{
size_t nodes_printed = 0;
char buffer[256];
int len;
ssize_t bytes_written;

while (h)
{
len = snprintf(buffer, sizeof(buffer), "[%u] %s\n",
h->len, (h->str ? h->str : "(nil)"));

if (len < 0 || (size_t)len >= sizeof(buffer))
{
return (nodes_printed);
}

bytes_written = write(1, buffer, (size_t)len);

/* Check for errors in write */
if (bytes_written < 0)
{
return (nodes_printed);
}

h = h->next;
nodes_printed++;
}
return (nodes_printed);
}

