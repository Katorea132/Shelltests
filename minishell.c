#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

void args(char *txt, char **arr)
{
	char *tmp = strdup(txt), *token;
	unsigned int i;
	
	printf("before loop 1 - args");
	for (i = 0, token = strtok(tmp, " \n"); token; i++, token = strtok(NULL, " \n"))
		;
	printf("after loop 1 - args");
	arr = malloc(sizeof(char) * i);
	if (!arr)
		printf("fail malloc1 - args"), exit(100);
	for (i = 0, token = strtok(txt, " \n"); token; i++, token = strtok(NULL, " \n"))
	{
		printf("inside loop 2 - args");
		arr[i] = malloc(sizeof(char) * (strlen(token)));
		if (!arr[i])
			printf("error malloc 2 args"), exit(199);
		arr[i] = token;
		printf("inside loop 2 - args: value of arr: %s", arr[i]);
	}
}
int main (int argc __attribute__((unused)), char **av)
{
	char *BUFFER;
	size_t bufsize = 1;
	char **argv = 0;

	BUFFER = malloc(sizeof(char) * 1);
	if (!BUFFER)
		return (9999);
	for (; ;)
	{
		printf("%s$ ", av[0]);
		getline(&BUFFER, &bufsize, stdin);
		args(BUFFER, argv);
		execve(argv[0], argv, 0);
	}
	return (0);
}