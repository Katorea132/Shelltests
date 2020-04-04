#include "header.h"

extern char **environ;

int _setenv(char *name, char *value, int overwrite)
{
	char *env_var;
	int i = 0;

	env_var = *(environ + i);

	while (env_var != NULL)
	{
		if (strcmp(name, env_var) == 0)
		{
			if (overwrite != 0)
				*(environ + i) = strcat(strcat(name, "="), value);
			return (0);
        }
		else
		{
			i++;
			env_var = *(environ + i);
		}
    }
       
	return (1);
}

int main (void)
{
	int i;

	i = _setenv("VAR1", "hgkhjfkhsb", 1);
	printf("i = %d\n", i);
	i = _setenv("VAR2", "ewurugfhdf", 1);
	printf("i = %d\n", i);

	return (0);
}