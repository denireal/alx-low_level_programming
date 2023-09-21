#include <stdlib.h>
#include <unistd.h>
#include "lists.h"

/**
* list_len - returns the number of elements in a linked list
* @h: pointer to the list_t list
*
* Return: number of elements in h
*/
size_t list_len(const list_t *h)
{
size_t n = 0;
char buffer[20];
int len;

while (h)
{
n++;
h = h->next;
}

len = snprintf(buffer, sizeof(buffer), "%lu\n", n);

if (len >= 0)
{
write(1, buffer, (size_t)len);
}

return (n);
}
}
