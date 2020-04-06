#include "shell.h"
/**
 * _atoiS - prints digits of a string
 * @s: Holds the string
 * Return: returns the value of the integer
 */
int _atoiS(char *s)
{
	int i, sign, digit, logic;

	logic = 0;
	digit = 0;
	sign = 1;
	for (i = 0; s[i] != 0;)
	{
		if (s[i] == '-')
		{
			sign *= -1;
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			digit *= 10;
			digit -= (s[i] - '0');
			logic = 1;
		}
		else if (logic == 1)
		{
			break;
		}
		i++;

	}
	digit *= -sign;
	return (digit);
}
/**
 * checkPATH - checks for the PATH
 * @arr0z: Holds the array on position 0z
 * @buf: Holds the struct for stat
 * Return: none
 */
void checkPATH(char *arr0z, struct stat *buf)
{
	int i;
	char *conpollo;

	if (stat(arr0z, buf) == 0 && buf->st_mode & S_IXUSR)
		return;
	conpollo = _strdupS(arr0z);
	for (i = 0; environ[i]; i++)
	{
		printf("loop-cehck\n");
		arr0z = str_concatS(str_concatS(environ[i], "/"), conpollo);
		if (stat(arr0z, buf) == 0 && buf->st_mode & S_IXUSR)
		{
			printf("insideif \n");
			free(conpollo);
			return;
		}
		printf("afterif%s\n", arr0z);
		free(arr0z);
		arr0z = 0;
	}
	printf("afterloopp\n");
	arr0z = _strdupS(conpollo);
	free(conpollo);
}
