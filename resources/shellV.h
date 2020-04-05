#ifndef SHELLY
#define SHELLY

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

extern char **environ;
/* These are inside stringS. */
char *_strdup(char *str);
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
/* These are inside stringS1. */
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int n);
char *_strpbrk(char *s, char *accept);
/* These are inside utilitiesS.c */
char *_memcpy(char *dest, char *src, unsigned int n);

#endif /* of SHELLY */