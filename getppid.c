#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t ppid;

	ppid = getppid();
	printf("%u\n", ppid);
	return (0);
}