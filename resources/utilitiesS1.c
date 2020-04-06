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
void checkPATH(char **arr, struct stat *buf)
{
	int i, j;
	char *conpollo, **lemon, *pathonized, *testy;

	if (stat(arr[0], buf) == 0 && buf->st_mode & S_IXUSR)
		return;
	conpollo = _strdupS(arr[0]);
	free(arr[0]);
	pathonized = _getenv("PATH");
	lemon = pathonizer(pathonized);
	free(pathonized);
	for (i = 0; lemon[i]; i++)
	{
		testy = str_concatS(lemon[i], "/");
		arr[0] = str_concatS(testy, conpollo);
		if (stat(arr[0], buf) == 0 && buf->st_mode & S_IXUSR)
		{
			free(conpollo);
			for (j = 0; lemon[j]; j++)
				free(lemon[j]);
			free(lemon);
			free(testy);
			return;
		}
		free(arr[0]);
		arr[0] = 0;
		free(testy);
		testy = 0;
	}
	for (j = 0; lemon[j]; j++)
		free(lemon[j]);
	free(lemon);
	lemon = 0;
	arr[0] = _strdupS(conpollo);
	free(testy);
	free(conpollo);
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

		if (strcmp(name, name_env) == 0)
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
/**
 * pathonizer - Divides the string into separated paths
 * @buf: Holds the string
 * Return: array of strings
 */
char **pathonizer(char *buf)
{
	char *tmp1 = 0, *tmp2 = 0, *token = 0, **arr = 0;
	int i;

	tmp1 = _strdupS(buf);
	tmp2 = _strdupS(buf);
	for (i = 0, token = strtok(tmp1, ":"); token; i++)
		token = strtok(NULL, ":");
	free(tmp1);
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == 0)
		perror("pathonizer function couldn't allocate memory"), exit(2);
	for (i = 0, token = strtok(tmp2, ":"); token; i++)
		arr[i] = _strdupS(token), token = strtok(NULL, ":");
	arr[i] = NULL;
	free(tmp2);
	return (arr);
}
