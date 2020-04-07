#include "shell.h"
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
