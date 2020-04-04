#include "header.h"

dir_t *reverse_end(dir_t *h)
{
	dir_t *aux;

	if (!h)
		return (NULL);

	aux = h;

	while (aux->next)
		aux = aux->next;

	return (aux);
}