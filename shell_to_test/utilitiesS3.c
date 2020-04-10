#include "shell.h"
/**
 * echoinator - Checks for $ in the echo
 * @arr: Holds the array of strings
 * @statusOut: Hold the last's function status
 * Return: none
 */
void echoinator(char **arr, int *statusOut)
{
	unsigned int i;

	for (i = 1; arr[i]; i++)
	{
		if (_strcmpS(arr[i], "$$") == 0)
		{
			free(arr[i]);
			arr[i] = intToStr(getpid());
		}
		else if (_strcmpS(arr[i], "$?") == 0)
		{
			free(arr[i]);
			arr[i] = intToStr(*statusOut);
		}
		else if (arr[i][0] == '$' &&
		(arr[i][1] != '$' || arr[i][1] != '?'))
		{
			decomposer(arr, i);
		}
	}
}
/**
 * decomposer - Decomposes both the echo argument and the environ
 * @decompositron: To be decomposed
 * @position: Holds position of decompositron
 * Return: none, everything that was is no more.
 */
void decomposer(char **decompositron, int position)
{
	unsigned int i, j;
	char *holder, *token, *gettyenv;

	holder = _strdupS(decompositron[position]);
	token = strtok(holder, "$");
	free(decompositron[position]);
	gettyenv = _getenv(token);
	decompositron[position] = _strdupS(gettyenv);
	free(gettyenv);
	free(holder);
	if (decompositron[0] == 0)
		decompositron[0] = "";
}
