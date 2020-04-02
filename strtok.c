#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char ten[] = "piñacolada";
	char ten1[] = "piñacolada";
	char *token, *pizza;
	char **arr;
	int i, len;

	for(i = 1, token = strtok(ten, "ñil"); token; token = strtok(NULL, "ñil"), i++)
		printf("%s\n", token);
	printf("fin de toquen\n");
	arr = malloc(sizeof(char) * i);
	if (!arr)
		perror("malito amalloc1"), exit (999999);
	for (i = 0, len = 0, pizza = strtok(ten1, "ñil"); pizza; pizza = strtok(NULL, "ñil"), i++)
	{
		len = strlen(pizza);
		arr[i] = malloc(sizeof(char) * len);
		if (!arr[i])
			perror("malito amalloc2"), exit (123123);
		arr[i] = pizza;
		printf("%s\n", arr[i]);
	}
	return (0);
}