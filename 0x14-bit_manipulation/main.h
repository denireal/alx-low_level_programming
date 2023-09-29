#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

/*
 * main.h
 * Description: Header file containing prototypes for all functions
 */

unsigned int binary_to_uint(const char *b);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);

/**
 * @param c The character to be printed
 * @return On success, returns the character that was printed. On error, returns -1.
 */
int _putchar(char c);

int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int get_endianness(void);

#endif
