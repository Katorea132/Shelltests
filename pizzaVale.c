#include "header.h"

dir_t **linkd(dir_t **head)
{
	char *dir1;
	char *dir2;

	dir1 = getenv("PATH");
	dir2 = strtok(dir1, ":");

	while (dir2)
	{
		add_node_end(head, dir2);
		dir2 = strtok(NULL, ":");
	}
	return (head);
}

int main (void)
{
	dir_t *head;
	dir_t *aux;
	dir_t **h;

	head = NULL;
	h = linkd(&head);

	aux = *h;
	while (aux)
	{
		printf("directory: %s\n", aux->dir);
		aux = aux->next;
	}
	return (0);
}