#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;

int main (void)
{
	int i, j, k;
	char const *pizza = "PATH";
	char *holder;

	for (i = 0; environ[i]; i++)
	{
		j = strncmp(environ[i], pizza, strlen(pizza));
		if (j == 0)
		{
			holder = strdup(environ[i]);
			for (k = strlen(pizza) + 1; holder[k]; k++)
				putchar(holder[k]);
			break;
		}
	}
	return (0);
}
