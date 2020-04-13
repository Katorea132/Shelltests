#include "shell.h"
/**
 * _strcmpS - compares strings
 * @s1: String 1
 * @s2: String 2
 * Return: 0 if same, different if not
 */
int _strcmpS(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != 0; a++)
		if (s1[a] < s2[a] || s1[a] > s2[a])
			return (s1[a] - s2[a]);
	return (0);
}
/**
 * _strchrS - Finds a character in a string
 * @s: Holds the string
 * @c: Holds the test character
 * Return: Returns a char pointer
 */
char *_strchrS(char *s, char c)
{
	for (; *s != 0; s++)
	{
		if (*s == c)
			return (s);
		else if (*(s + 1) == c)
			return (s + 1);
	}
	return (0);
}
/**
 * _strncatS - Concatenates 2 string, only including "n" strings
 * @dest: Holds string 1
 * @src: Holds string 2
 * @n: Holds the amount of values to concatenate
 * Return: char
 */
char *_strncatS(char *dest, char *src, int n)
{
	int a, b;

	for (a = 0; dest[a] != 0; a++)
		;
	for (b = 0; src[b] != 0 && b < n; b++)
		dest[a + b] = src[b];
	dest[a + b] = 0;
	return (dest);
}
/**
 * _strpbrkS - Searches a string for any set of bytes
 * @s: Holds the string
 * @accept: Holds the test
 * Return: returns a pointer char
 */
char *_strpbrkS(char *s, char *accept)
{
	int a, b;

	for (a = 0; s[a] != 0; a++)
		for (b = 0; accept[b] != 0; b++)
			if (s[a] == accept[b])
				return (&s[a]);
	return (0);
}
