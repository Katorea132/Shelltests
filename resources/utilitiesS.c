#include "shell.h"
/**
 * _memcpyS - copies n bytes from a memory area to another
 * @dest: Holds the place to be copied at
 * @src: Holds the values to be copied
 * @n: Determines the amount of bytes to copy
 * Return: returns a char
 */
char *_memcpyS(char *dest, char *src, unsigned int n)
{
	unsigned int b;

	for (b = 0; b < n; b++)
	{
		*(dest + b) = *(src + b);
	}
	return (dest);
}
/**
 * commandExec - Executes the command if it is found
 * @getty: Tells whether getline worked or nah
 * @buffer: Holds the string retrieved by getline
 * @arr: Holds the array to put in the commands
 * @argv: Holds the arguments passed to main (only using the name)
 * @found: boolean to see if enters or not in the function
 * Return: none
 */
void commandExec(int getty, char *buffer, char **arr, char **argv, int found)
{
	pid_t piddy = 0;
	struct stat buf;
	char *dupHold;

	if (getty != -1 && buffer[0] != '\n' && found == 0)
	{
		arr = command(buffer);
		dupHold = _strdupS(arr[0]);
		checkPATH(&dupHold, &buf);
		if (stat(dupHold, &buf) == 0 && buf.st_mode & S_IXUSR)
		{
			piddy = fork();
			if (piddy == 0)
				execve(dupHold, arr, environ);
			else
				wait(NULL);
		}
		else
			writeErr(argv[0], arr[0]);
		WilliamWallace(arr);
		free(dupHold);
	}
}
/**
 * customCmmExec - Executes the command if it is found
 * @getty: Tells whether getline worked or nah
 * @buffer: Holds the string retrieved by getline
 * @arr: Holds the array to put in the commands
 * @chkVal: Holds boolean to dertemine if the code must be executed or not
 * Return: 1 if a built in or 0 if not
 */
int customCmmExec(int getty, char *buffer, char **arr, int chkVal)
{
	if (chkVal == 0)
	{
		if (getty != -1 && buffer[0] != '\n')
		{
			arr = command(buffer);
			if (_strcmpS("exit", arr[0]) == 0)
			{
				execExit(buffer, arr);
				WilliamWallace(arr);
				return (1);
			}
			else if (_strcmpS("env", arr[0]) == 0)
			{
				execEnv();
				WilliamWallace(arr);
				return (1);
			}
			WilliamWallace(arr);
		}
		return (0);
	}
	return (1);
}
/**
 * execExit - Executes exit
 * @buffer: Holds the string
 * @arr: Holds the array of strings
 * Return: none
 */
void execExit(char *buffer, char **arr)
{
	int i, j, status;

	for (i = 0; arr[i]; i++)
		;
	if (i == 1)
	{
		free(buffer);
		WilliamWallace(arr);
		exit(0);
	}
	else if (i == 2)
	{
		for (j = 0; arr[1][j]; j++)
		{
			if (arr[1][j] < 48 || arr[1][j] > 57)
			{
				write(STDOUT_FILENO, "Usage: exit status\n", 19);
				return;
			}
		}
		status = _atoiS(arr[1]);
		free(buffer);
		WilliamWallace(arr);
		exit(status);
	}
	else
	{
	write(STDOUT_FILENO, "Usage: exit status\n", 19);
	return;
	}
}
/**
 * execEnv - Executes env
 * Return: none
 */
void execEnv(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlenS(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
