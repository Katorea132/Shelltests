#ifndef HEADER_H
#define HEADER_H
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

typedef struct dir_s
{
	char *dir;
	struct dir_s *next;
} dir_t;


extern char **environ;
char *_getenv(const char *name);
int dir(void);
dir_t **linkd(dir_t **head);
dir_t *add_node_end(dir_t **head, char *s);
dir_t *reverse_end(dir_t *h);

#endif