#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main (int ac, char **av)
{
	int i, j;

	for (j = 0; av[j]; j++)
		printf("%s\n", av[j]);	
	return (0);		
}