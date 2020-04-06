#include "shellV.h"

/**
 * _strcmp - function that compares two strings
 * @s1: first string to compare
 * @s2: second string to compare
 * Return: 0
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0')

	{
		if (s1[i] > s2[i])
			return (s1[i] - s2[i]);
		if (s1[i] < s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/**
 * _strchr - function that locates a character in a string
 * @s: string
 * @c: character
 * Return: a pointer to the first occurrence of the character
 * or NULL if the character is not found
 */

char *_strchr(char *s, char c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return (s);
		else if (*(s + 1) == c)
			return (s + 1);
		s++;
	}
	return (s + 1);
}

/**
 *_strncat - concatenates two strings
 *@dest: pointer parameter destination
 *@src: pointer parameter source
 *@n: parameter integer number
 *Return: destination variable
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0, x = 0, k = 0, y = 0;

	while (dest[i])
		i++;

	while (src[y])
		y++;

	if (n < y)
	{
		n += i;

		for (j = i; j < n; j++)
		{
			dest[j] = src[x];
			x++;
		}
	}
	else
	{
		n = i + y;

		for (k = i; k < n; k++)
		{
			dest[k] = src[x];
			x++;
		}
	}

	return (dest);
}

/**
 *_strpbrk - searches a string for any of a set of bytes.
 *@s: pointer parameter
 *@accept: pointer parameter, value accept
 *Return: s variable
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j, n = 0, x = 0;

	while (s[n])
		n++;

	while (accept[x])
		x++;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= x; j++)
		{
			if (s[i] == accept[j])
				return (s + i);
		}
	}

	s = 0;
	return (s);
}
