#include "shell.h"
/**
 * echoinator - Checks for $ in the echo
 * @arr: Holds the array of strings
 * @statusOut: Hold the last's function status
 * Return: none
 */
void echoinator(char **arr, unsigned int *statusOut)
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
void decomposer(char **decompositron, unsigned int position)
{
	char *holder, *token, *gettyenv;

	holder = _strdupS(decompositron[position]);
	token = strtok(holder, "$");
	free(decompositron[position]);
	gettyenv = _getenv(token);
	decompositron[position] = _strdupS(gettyenv);
	free(gettyenv);
	free(holder);
	if (decompositron[position] == 0)
		decompositron[position] = _strdupS("");
}
/**
 * variableinator - Variableinatices variables
 * @arr: Holds the array of strings
 * @statusOut: Holds the exit status
 * @counter: Amount of commands sent so far
 * @argv: Holds the arguments passed to main
 * Return: none
 */
void variableinator(char **arr, unsigned int *statusOut,
int counter, char **argv)
{
	unsigned int i;
	char *keyHold, *token;

	for (i = 0; arr[i]; i++)
		;
	if (i > 1)
	{
		writeErr(argv[0], arr[1], counter), *statusOut = 127;
		return;
	}
	token = strtok(arr[0], "=");
	if (token == 0)
		perror("variableinator couldn't allocate memory\n"), exit(1);
	keyHold = _strdupS(token);
	token = strtok(NULL, "=");
	if (token == 0)
	{
		free(keyHold), *statusOut = 0;
		return;
	}
	free(keyHold);
}
