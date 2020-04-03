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
	arr = malloc(sizeof(char) * i);
	for (i = 0, token = strtok(tmp2, " \n"); token; i++, token = strtok(NULL, " \n"))
		arr[i] = strdup(token);
	free(tmp2);
	free(buf);
	return (arr);	
}
int main (int ac __attribute__((unused)), char **argv)
{
	char *buffer = 0, **arr;
	unsigned long int len;
	pid_t piddy;

	for (; ;)
	{
		piddy = fork();
		if (piddy == 0)
		{
			printf("%s$ ", argv[0]);
			getline(&buffer, &len, stdin);
			arr = command(buffer);
			execve(arr[0], arr, NULL);
		}
		else
		{
			wait(NULL);
			free (arr);
		}
		
	}
	return (0);
}