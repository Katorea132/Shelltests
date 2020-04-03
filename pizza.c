#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
extern char **environ;
typedef struct patty
{
	char *str;
	struct patty *next;
} patty;
patty *tupac(patty **pat, char *pan)
{
	patty *pun, *tty;

	pun = malloc(sizeof(patty));
	if (!pun)
		return (0);
	pun->str = strdup(pan);
	pun->next = 0;
	if (*pat == 0)
		*pat = pun;
	else
	{
		tty = *pat;
		while (tty->next != 0)
			tty = tty->next;
		tty->next = pun;
	}
	return (pun);
	
}
void divnconq (char *patteruni, patty **pat)
{
	/* PATTY CAKE, PATTY CAKE, BAKERS PAN!*/
	char *patty, *cake, *bakers, **pan;
	int i;

	patty = strdup(patteruni);
	cake = strdup(patteruni);
	for (i = 0, bakers = strtok(patty, ":"); bakers; i++, bakers = strtok(NULL, ":"))
		;
	free (patty);
	pan = malloc(sizeof(char *) * i);
	for (i = 0, bakers = strtok(cake, ":"); bakers; i++, bakers = strtok(NULL, ":"))
		pan[i] = strdup(bakers), tupac(pat, pan[i]);
	free(cake);
	free(pan);
}
int main (void)
{
	patty *pat = NULL;
	char *patteruni = strdup(getenv("PATH"));
	int i;

	divnconq (patteruni, &pat);
	for (i = 0; pat; i++, pat = pat->next)
		printf("%s\n", pat->str);
	return (0);
}