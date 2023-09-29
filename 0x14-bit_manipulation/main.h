#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdio.h>

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 *
 * @b: A pointer to a string containing '0' and '1' characters.
 *
 * Return: The converted number, or 0 if there are invalid characters
 * in the string or if b is NULL.
 */
unsigned int binary_to_uint(const char *b);

/**
 * print_binary - Prints the binary representation of an unsigned long int.
 *
 * @n: The unsigned long int to be printed in binary.
 */
void print_binary(unsigned long int n);

/**
 * get_bit - Gets the value of a bit at a given index.
 *
 * @n: The unsigned long int.
 * @index: The index of the bit to retrieve (0-based).
 *
 * Return: The value of the bit at the specified index,
 * or -1 if an error occurs.
 */
int get_bit(unsigned long int n, unsigned int index);

/**
 * _putchar - Writes a character to the standard output.
 *
 * @c: The character to be written.
 *
 * Return: On success, returns the character that was written.
 * On error, returns -1.
 */
int _putchar(char c);

/**
 * set_bit - Sets the value of a bit at a given index to 1.
 *
 * @n: A pointer to the unsigned long int.
 * @index: The index of the bit to set (0-based).
 *
 * Return: 1 if successful, or -1 if an error occurs.
 */
int set_bit(unsigned long int *n, unsigned int index);

/**
 * clear_bit - Sets the value of a bit at a given index to 0.
 *
 * @n: A pointer to the unsigned long int.
 * @index: The index of the bit to clear (0-based).
 *
 * Return: 1 if successful, or -1 if an error occurs.
 */
int clear_bit(unsigned long int *n, unsigned int index);

/**
 * flip_bits - Counts the number of bits needed to flip to convert
 * one number to another.
 *
 * @n: The first unsigned long int.
 * @m: The second unsigned long int.
 *
 * Return: The number of bits needed to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/**
 * get_endianness - Determines the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void);

#endif
