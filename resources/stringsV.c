#include "shellV.h"
/**
 * _strdup - function that returns a pointer to a newly allocated
 * space in memory
 * @str: string
 * Return: NULL if str = NULL
 */

char * _strdup(char *str)
{
	char *p;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;
	i++;
	p = malloc((sizeof(char) * 1 ) + i);
	if (p == NULL)
		return (NULL);
	j = 0;
	while (j < i)
	{
		p[j] = str[j];
		j++;
	}
	return (p);
}

char *str_concat(char *s1, char *s2)
{
	char *p;
	unsigned int length1 = 0, length2 = 0, i, j;

	if (s1 == '\0')
		s1 = "";
	if (s2 == '\0')
		s2 = "";
	length1 = 0;
	while (s1[length1] != '\0')
		length1++;
	length2 = 0;
	while (s2[length2] != 0)
		length2++;
	p = malloc(sizeof(char) * (length1 + length2 + 1));
	if (p != NULL)
	{
		for (i = 0; s1[i] != '\0'; i++)
		{
			p[i] = s1[i];
		}
		for (j = 0; s2[j] != '\0'; j++)
		{
			p[length1 + j] = s2[j];
		}
	}
	return (p);
}

/**
 * _strlen - function that returns the length of a string
 * @s: is a string
 * Return: length of string
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != 0)
		i++;
	return (i);
}

/**
* *_strcpy - copies string pointed to by src to buffer pointed to by dest
* @dest: the pointer to a string
* @src: the pointer to a buffer
* Return: the value of the pointer to dest.
*/
char *_strcpy(char *dest, char *src)
{
int i;

i = 0;
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}
dest[i] = '\0';
return (dest);
} 


/**
 * _strcat - Function that concatenates two strings
 * @dest: string
 * @src: string
 * Return: a pointer to the result string dest
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0 ; (dest[i] != '\0'); i++)
	;

	j = 0;

	while (src[j] != '\0')

	{
		dest[i] = src[j];
		j++;
		i++;
	}
	i++;
	dest[i] = '\0';
	return (dest);

}