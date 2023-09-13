#ifndef _FUNCT_PTR_H
#define _FUNCT_PTR_H

#include <stdio.h>

/* Desc: header file */
/* prototypes of all functions and prototype of the function _putchar */
int _putchar(char c);
void print_name(char *name, void (*f)(char *));
void array_iterator(int *array, size_t size, void (*action)(int));
int int_index(int *array, int size, int (*cmp)(int));

#endif
