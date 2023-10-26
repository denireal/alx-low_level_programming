#include "main.h"

/**
* get_endianness - Determine the system's endianness.
*
* This function checks the endianness of the system to determine
* whether it is big-endian or little-endian.
*
* Return: 0 if the system is big-endian, 1 if it is little-endian.
*/
int get_endianness(void)
{
return (*(char *)&(int){1} == 1);
}
