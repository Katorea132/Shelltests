#include "shell.h"
char *_getenv(const char *name)
{
	int i;
	char *copy, *val, *name_env, *sender;

	for (i = 0; environ[i]; i++)
	{
		copy = _strdupS(environ[i]);
		name_env = strtok(copy, "=");

		if (_strcmpS((char *)name, name_env) == 0)
		{
			val = strtok(NULL, "=");
			sender = _strdupS(val);
			free(copy);
			return (sender);
		}
		free(copy);
	}
	return (NULL);
}
/**
 * WilliamWallace - Freedom for Scotland!
 * @liberty: FREEDOM!
 * Return: Only freedom
 */
void WilliamWallace(char **liberty)
{
	int i;

	for (i = 0; liberty[i]; i++)
		free(liberty[i]);
	free(liberty);
}

void main(void)
{
	int i;

	initializer();
	_setenv("pollo", "", 0);
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	_unsetenv("aguacate");
	for (i = 0; environ[i]; i++)
		printf("%s\n", environ[i]);
	WilliamWallace(environ);
}