#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
char **command (char *buf)
{
	char *tmp1, *tmp2, *token, **arr;
	int i;

	tmp1 = strdup(buf);
	tmp2 = strdup(buf);
	for (i = 0, token = strtok(tmp1, " \n"); token; i++, token = strtok(NULL, " \n"))
		;
	free(tmp1);
	arr = malloc(sizeof(char *) * i);
	for (i = 0, token = strtok(tmp2, " \n"); token; i++, token = strtok(NULL, " \n"))
		arr[i] = strdup(token);
	free(tmp2);
	return (arr);	
}
int main (int ac __attribute__((unused)), char **argv)
{
	char *buffer = 0, **arr;
	unsigned long int len, i;
	pid_t piddy;

	for (; ;)
	{
		printf("%s$ ", argv[0]);
		getline(&buffer, &len, stdin);
		arr = command(buffer);
		piddy = fork();
		if (piddy == 0)
		{
			execve(arr[0], arr, NULL);
			break;
		}
		else
		{
			wait(NULL);
			free (arr);
			for (i = 0; arr[i]; i++)
				free (arr[i]);
			free(buffer);
		}
		
	}
	return (0);
}