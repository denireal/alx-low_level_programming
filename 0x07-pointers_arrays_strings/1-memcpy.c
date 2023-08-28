/**
* _memcpy - Copies n bytes from memory area src to memory area dest
* @dest: Pointer to destination memory area
* @src: Pointer to source memory area
* @n: Number of bytes to copy
*
* Return: Pointer to dest
*/

char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *original_dest = dest;

	while (n--)
	{
		*dest++ = *src++;
	}
	return (original_dest);
}
