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
	if (decompositron[0] == 0)
		decompositron[0] = "";
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
	char *keyHold, *valueHold, *token;

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
	valueHold = _strdupS(token);
	if (valueHold == 0)
		perror("variableinator couldn't allocate memory\n"), exit(1);
	echoinador(&valueHold, statusOut);

}
/**
 * arrainator - Copies and then adds a new element to an array
 * @value: Value to add
 * @picker: Determines which array to modify, 1 keys, 2 values, 3 environ
 * Return: none
 */
void arrainator(char *value, int picker)
{
	unsigned int i;
	char **replacer;

	if (picker == 1)
	{
		for (i = 0; keys[i]; i++)
			;
		replacer = malloc(sizeof(char *) * (i + 2));
		if (replacer == 0)
			perror("arrainator couldn't allocate memory\n"), exit(1);
		for (i = 0; keys[i]; i++)
		{
			replacer[i] = _strdupS(keys[i]);
			if (replacer[i] == 0)
				perror("variableinator couldn't allocate memory\n"), exit(1);
		}
		replacer[i + 1] = _strdupS(value);
		replacer[i + 2] = 0;
	}
	else if (picker == 2)
	{
		for (i = 0; values[i]; i++)
			;
		replacer = malloc(sizeof(char *) * (i + 2));
		if (replacer == 0)
			perror("arrainator couldn't allocate memory\n"), exit(1);
		for (i = 0; values[i]; i++)
		{
			replacer[i] = _strdupS(values[i]);
			if (replacer[i] == 0)
				perror("variableinator couldn't allocate memory\n"), exit(1);
		}
		replacer[i + 1] = _strdupS(value);
		replacer[i + 2] = 0;
	}
}
