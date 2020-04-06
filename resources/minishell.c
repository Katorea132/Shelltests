#include "shell.h"
/**
 * command - Divides the string into commands
 * @buf: Holds the string
 * Return: array of strings
 */
char **command (char *buf)
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
void writedol(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
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
 * main - Main
 * @ac: Argument count
 * @argv: arguments
 * Return: 0 if succeeds, something else if not
 */
int main (int ac __attribute__((unused)), char **argv)
{
	char *buffer = 0, **arr = 0;
	unsigned long int len = 0, i = 0;
	int getty = 1;
	pid_t piddy = 0;
	struct stat buf;

	while (getty != -1)
	{
		writedol();
		getty = getline(&buffer, &len, stdin);
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
				free (arr[i]);
			free(arr);
		}
		free(buffer);
		buffer = 0;
	}
	return (0);
}