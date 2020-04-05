#include "shell.h"
/**
 * _strdupS - Returns a pointer to a newly allocated space in memory
 * @str: Holds the string to be copied
 * Return: a pointer to a char
 */
char *_strdupS(char *str)
{
	char *strc;
	int i;

	if (str == 0)
		return (0);
	for (i = 0; str[i] != 0; i++)
		;
	strc = malloc((sizeof(char) * 1) + i);
	if (strc == 0)
		return (0);
	for (i = 0; str[i] != 0; i++)
		strc[i] = str[i];
	strc[i] = 0;
	return (strc);
}
/**
 * str_concatS - Concatenates 2 strings
 * @s1: Holds string 1
 * @s2: Holds string 2
 * Return: a pointer to a char
 */
char *str_concatS(char *s1, char *s2)
{
	char *conc;
	int lens1, lens2, i;

	if (s1 == 0)
		s1 = "";
	if (s2 == 0)
		s2 = "";
	for (lens1 = 0; s1[lens1] != 0; lens1++)
		;
	for (lens2 = 0; s2[lens2] != 0; lens2++)
		;
	conc = malloc((sizeof(char) * (lens1 + lens2)) + 1);
	if (conc == 0)
		return (0);
	for (i = 0; i < lens1; i++)
		conc[i] = s1[i];
	lens1 = i;
	for (i = 0; i < lens2; i++, lens1++)
		conc[lens1] = s2[i];
	conc[lens1] = 0;
	return (conc);
}
/**
 * _strlenS - It returns the lenght of a string
 * @s: Holds the string
 * Return: none
 */
int _strlenS(char *s)
{
	int a;

	for (a = 0; s[a] != 0; a++)
		;
	return (a);
}
/**
 * _strcpyS - copies 1 string into another including the null
 * @dest: Space to put the string
 * @src: Holds the string
 * Return: returns the buffer pointed by dest
 */
char *_strcpyS(char *dest, char *src)
{
	int a;

	for (a = 0; src[a] != 0; a++)
		dest[a] = src[a];
	dest[a] = 0;
	return (dest);
}
/**
 * _strcatS - Concatenates 2 strings, overwritting the terminating null
 * @dest: Holds the string 1
 * @src: Holds the string 2
 * Return: Returns chars
 */
char *_strcatS(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != 0; a++)
		;
	for (b = 0; src[b] != 0; b++)
		dest[a + b] = src[b];
	dest[a + b] = 0;
	return (dest);
}
