#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern char **environ;

char *_getenv(const char *name)
{
	int i;
	char *copy, *val, *name_env;

	for (i = 0; environ[i]; i++)
	{
		copy = strdup(environ[i]);
		name_env = strtok(copy, "=");

		if (strcmp((char *)name, (char *)name_env) == 0)
		{
			val = strtok(NULL, "=");
			return (val);
		}
	}
		return (NULL);
}

#include <stdlib.h>

int main () 
{
    printf("PATH : %s\n", _getenv("PATH"));
    return(0);
}