#include "shell.h"
/**
 * _memcpyS - copies n bytes from a memory area to another
 * @dest: Holds the place to be copied at
 * @src: Holds the values to be copied
 * @n: Determines the amount of bytes to copy
 * Return: returns a char
 */
char *_memcpyS(char *dest, char *src, unsigned int n)
{
	unsigned int b;

	for (b = 0; b < n; b++)
	{
		*(dest + b) = *(src + b);
	}
	return (dest);
}