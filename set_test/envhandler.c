#include "shell.h"
/**
 * initializer - initializes own copy of environ
 * Return: none
 */
void initializer(void)
{
	int i;
	char **primer;

	for (i = 0; environ[i]; i++)
		;
	primer = malloc(sizeof(char *) * (i + 1));
	for (i = 0; environ[i]; i++)
		primer = _strdupS(environ[i]);
	environ[i] = 0;
}
/**
 * _setenv - Sets a variable in a pirate way
 * @key: The variable to set
 * @value: The value to be set with
 * @overwrite: Whether overwrite or not such variable
 * Return: 0 on success, -1 on failure
 */
int _setenv(char *key, char *value, int overwrite)
{
	char *toFree = _getenv(key), **toHold, *toUnite;
	int i;

	if (key == 0 || _strlenS(key) == 0)
	{
		write(STDERR_FILENO, "Name is invalid\n", 13);
		return (-1);
	}
	for (i = 0; key[i]; i++)
		if (key[i] == '=')
		{
			write(STDERR_FILENO, "Name is invalid\n", 13);
			return (-1);
		}
	if (toFree == 0)
	{
		for (i = 0; environ[i]; i++)
			;
		toHold = malloc(sizeof(char *) * (i + 2));
		if (toHold == 0)
			exit(1);
		for (i = 0; environ[i]; i++)
			toHold[i] = _strdupS(environ[i]);
		toUnite = str_concatS(key, "="), toHold[i] = str_concatS(toUnite, value);
		toHold[i + 1] = 0, free(toUnite), WilliamWallace(environ);
		environ = toHold;
		return (0);
	}
	else if (toFree != 0 && overwrite == 1)
		for (i = 0; environ[i]; i++)
			if (_strcmpS(key, environ[i] == 0))
			{
				free(environ[i]);
				toUnite = str_concatS(key, "="), environ[i] =  str_concatS(toUnite, value);
				free(toFree), free(toUnite);
				return (0);
			}
	free(toFree);
	return (0);
}
