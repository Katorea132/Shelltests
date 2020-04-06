#ifndef CHELLY
#define CHELLY

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;
/* These are inside stringS. */
char *_strdupS(char *str);
char *str_concatS(char *s1, char *s2);
int _strlenS(char *s);
char *_strcpyS(char *dest, char *src);
char *_strcatS(char *dest, char *src);
/* These are inside stringS1. */
int _strcmpS(char *s1, char *s2);
char *_strchrS(char *s, char c);
char *_strncatS(char *dest, char *src, int n);
char *_strpbrkS(char *s, char *accept);
/* These are inside utilitiesS.c */
char *_memcpyS(char *dest, char *src, unsigned int n);
void commandExec(int getty, char *buffer, char **arr, char **argv, int found);
int customCmmExec(int getty, char *buffer, char **arr);
void execExit(char *buffer, char **arr);
void execEnv(void);
/* These are inside utilitiesS1.c */
int _atoiS(char *s);
void checkPATH(char **arr, struct stat *buf);
char *_getenv(const char *name);
char **pathonizer(char *buf);
/* These are in minishell.c */
char **command(char *buf);
void writedol(void);
void writeErr(char *name, char *comm);
void ctrlC(int signal __attribute__((unused)));

#endif /* of CHELLY */
