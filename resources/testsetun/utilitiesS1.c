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
 * _getenv - Gets the dir of a environ thingie
 * @name: The name to search for
 * Return: the value of the thingie
 */
char *_getenv(const char *name)
{
	int i;
	char *copy, *val, *name_env, *sender;

	for (i = 0; environ[i]; i++)
	{
		copy = _strdupS(environ[i]);
		name_env = strtok(copy, "=");

		if (_strcmpS((char *)name, name_env) == 0)
		{
			val = strtok(NULL, "=");
			sender = _strdupS(val);
			free(copy);
			return (sender);
		}
		free(copy);
	}
	return (NULL);
}
