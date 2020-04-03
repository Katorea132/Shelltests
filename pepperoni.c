#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
int main(void)
{
	int i, j;
	char *p, *entry = "Pizza", *val = "aguacate", **megaenv;
	printf("%lu\n", sizeof(environ));
	for(i = 0;environ[i];i++)
		;
	p = getenv(entry);
	if (!p)
	{
		megaenv = malloc(sizeof(char *) * (i + 2));
		for (j = 0; j < i + 1; j++)
			megaenv[j] = strdup(environ[j]);
		megaenv[j] = malloc(sizeof(char) * ((strlen(entry) + (strlen(val) + 2))));
		/*megaenv[j] = entry, megaenv[j] = strcat(megaenv[j], "=");
		megaenv[j] = strcat(megaenv[j], val);*/
	}
	for (i = 0; megaenv[i]; i++)
		printf("%s\n", megaenv[i]);

	return (0);
}
