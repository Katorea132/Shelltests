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
/**
 * Commentator - Terminates anything after a #
 * @getty: Checks if it should be executed or no
 * @buffer: Holds the buffer whose comments are to be termianted
 * Return: a pointer to the new, comment free, buffer-> neobufer
 */
char *Commentator(int getty, char *buffer)
{
	char *neobuf;
	int i, j;

	if (getty != -1)
	{
		for (i = 0; buffer[i] != '#' && buffer[i] != 0; i++)
			;
		neobuf = malloc(sizeof(char) * (i + 1));
		if (!neobuf)
		{
			perror("Failed to allocate memory at Commentator");
			return (0);
		}
		for (j = 0; j < i; j++)
			neobuf[j] = buffer[j];
		neobuf[j] = 0;
		free(buffer);
		return (neobuf);
	}
	free(buffer);
	return (0);
}
