#include "shell.h"
/**
 * command - Divides the string into commands
 * @buf: Holds the string
 * Return: array of strings
 */
char **command(char *buf)
{
	char *tmp1 = 0, *tmp2 = 0, *token = 0, **arr = 0;
	int i;

	tmp1 = _strdupS(buf);
	tmp2 = _strdupS(buf);
	for (i = 0, token = strtok(tmp1, " \n"); token; i++)
		token = strtok(NULL, " \n");
	free(tmp1);
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == 0)
		perror("command function couldn't allocate memory"), exit(2);
	for (i = 0, token = strtok(tmp2, " \n"); token; i++)
		arr[i] = _strdupS(token), token = strtok(NULL, " \n");
	arr[i] = NULL;
	free(tmp2);
	return (arr);
}
/**
 * writedol - Writes or not the prompt depending on if
 * input comes from an FD associated with terminal or not
 * Return: none
 */
void writedol(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
/**
 * writeErr - Writes either error prompt depending on if
 * input comes from an FD associated with terminal or not
 * @name: Name of the program to print
 * @comm: Command given to print
 * Return: none
 */
void writeErr(char *name, char *comm)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, comm, _strlenS(comm));
		write(STDOUT_FILENO, ": command not found\n", 20);
	}
	else
	{
		write(STDOUT_FILENO, name, _strlenS(name));
		write(STDOUT_FILENO, ": 1: ", 5);
		write(STDOUT_FILENO, comm, _strlenS(comm));
		write(STDOUT_FILENO, ": not found\n", 12);
	}
}
/**
 * ctrlC - Handles SIGINT Ctrl+C
 * @signal: Recieves the signal
 * Return: none
 */
void ctrlC(int signal __attribute__((unused)))
{
	(void)signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - Main
 * @ac: Argument count
 * @argv: arguments
 * Return: 0 if succeeds, something else if not
 */
int main(int ac __attribute__((unused)), char **argv)
{
	char *buffer = 0, **arr = 0;
	unsigned long int len = 0;
	int getty = 1, found;

	while (getty != -1)
	{
		writedol();
		signal(SIGINT, ctrlC);
		getty = getline(&buffer, &len, stdin);
		found =  customCmmExec(getty, buffer, arr);
		putchar(found + '0');
		commandExec(getty, buffer, arr, argv);
		free(buffer);
		buffer = 0;
	}
	return (0);
}
