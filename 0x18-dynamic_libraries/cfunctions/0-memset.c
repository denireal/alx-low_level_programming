/**
* _memset - function that fills memory with a constant byte
* @s: the memory area
* @b: the constant byte
* @n: the number of bytes
*
* Return: returns a pointer to the memory area s
*/

char *_memset(char *s, char b, unsigned int n)
{
	char *original_ptr = s;

	while (n-- > 0)
	{
		*s++ = b;
	}
	return (original_ptr);
}
