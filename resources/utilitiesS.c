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
 * Return: none
 */
void commandExec(int getty, char *buffer, char **arr, char **argv)
{
	pid_t piddy = 0;
	struct stat buf;
	unsigned long i = 0;

	if (getty != -1 && buffer[0] != '\n')
	{
		arr = command(buffer);
		if (stat(arr[0], &buf) == 0 && buf.st_mode & S_IXUSR)
		{
			piddy = fork();
			if (piddy == 0)
				execve(arr[0], arr, NULL);
			else
				wait(NULL);
		}
		else
			writeErr(argv[0], arr[0]);
		for (i = 0; arr[i]; i++)
			free(arr[i]);
		free(arr);
	}
}
/**
 * commandExec - Executes the command if it is found
 * @getty: Tells whether getline worked or nah
 * @buffer: Holds the string retrieved by getline
 * @arr: Holds the array to put in the commands
 * Return: 1 if a built in or 0 if not
 */
int customCmmExec(int getty, char *buffer, char **arr)
{
	int i;
	if (getty != -1 && buffer[0] != '\n')
	{
		arr = command(buffer);
		if (_strcmpS("exit", arr[0]) == 0)
		{
			execExit(buffer, arr);
			for (i = 0; arr[i]; i++)
				free(arr[i]);
			free(arr);
			return (1);
		}
		/*else if (_strcmpS("env", arr[0]) == 0);
		{
			execEnv(arr);
			return (1);
		}*/
		for (i = 0; arr[i]; i++)
			free(arr[i]);
		free(arr);
	}
	return (0);
}
void execExit(char *buffer, char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		;
	if (i == 1)
	{
		free(buffer);
		for (i = 0; arr[i]; i++)
			free(arr[i]);
		free(arr);
		exit(0);
	}
}
