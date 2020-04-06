#include "header.h"

dir_t *add_node_end(dir_t **head, char *s)
{
	dir_t *end_node;
	dir_t *aux;

	end_node = malloc(sizeof(dir_t));

	if (!end_node)
		return (NULL);

	end_node->dir = s;
	end_node->next = NULL;

	if (*head == NULL)
		*head = end_node;
	else
	{
		aux = reverse_end(*head);
		aux->next = end_node;
	}
	return (end_node);
}