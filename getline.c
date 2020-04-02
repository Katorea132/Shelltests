#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *BUFF;
	size_t buffer = 1, chars;

	BUFF = malloc(buffer * sizeof(char));
	if (!BUFF)
		perror("Can't allocate memory"), exit (99);
	printf("$ ");
	chars = getline(&BUFF, &buffer, stdin);
	printf("%lu\n%s", buffer, BUFF);
	free(BUFF);
	return (0);
}