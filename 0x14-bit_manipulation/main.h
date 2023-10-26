#ifndef MAIN_H_
#define MAIN_H_

#include <stdlib.h>
#include <stdio.h>

/*
 * File: main.h
 *
 * Description: This header file includes function prototypes for all the
		functions in the 0x13-bit_manipulation directory. It also
		guards against double inclusion with header guards.
 */

unsigned int binary_to_uint(const char *b);
int _putchar(char c);
void print_binary(unsigned long int n);
int get_bit(unsigned long int n, unsigned int index);
int set_bit(unsigned long int *n, unsigned int index);
int clear_bit(unsigned long int *n, unsigned int index);
unsigned int flip_bits(unsigned long int n, unsigned long int m);
int get_endianness(void);

#endif
