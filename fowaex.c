#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	unsigned int i;
	char *pizza[] = {"/bin/ls", "-l", "/tmp", NULL};
	pid_t piddy;

	for (i = 0; i < 5; i++)
	{
		piddy = fork();
		if (piddy == 0)
		{
			execve(pizza[0], pizza, NULL);
		}
		else
		{
			wait(NULL);
			printf("______________________________________________________________\n\n");
		}
	}
	return (9);
}
