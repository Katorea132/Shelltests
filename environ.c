#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main (int ac, char **av, char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	printf("_______________________\n");
	for (i = 0; env[i]; i++)
		printf("%s\n", env[i]);
	return (0);
}