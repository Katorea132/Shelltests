#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
char **command (char *buf)
{
	char *tmp1 = 0, *tmp2 = 0, *token = 0, **arr = 0;
	int i;

	tmp1 = strdup(buf);
	tmp2 = strdup(buf);
	for (i = 0, token = strtok(tmp1, " \n"); token; i++)
		token = strtok(NULL, " \n");
	free(tmp1);
	arr = malloc(sizeof(char *) * (i + 1));
	for (i = 0, token = strtok(tmp2, " \n"); token; i++)
		arr[i] = strdup(token), token = strtok(NULL, " \n");
	arr[i] = NULL;
	free(tmp2);
	return (arr);	
}
int main (int ac __attribute__((unused)), char **argv)
{
	char *buffer = 0, **arr = 0;
	unsigned long int len = 0, i = 0;
	int getty = 1;
	pid_t piddy = 0;
	struct stat buf;

	while (getty != -1)
	{
		write(1, argv[0], strlen(argv[0]));
		write(1, "$ ", 2);
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
			for (i = 0; arr[i]; i++)
				free (arr[i]);
			free(arr);
		}
		free(buffer);
		buffer = 0;
	}
	return (0);
}