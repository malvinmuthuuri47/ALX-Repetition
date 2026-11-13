#include "lists.h"

/**
 * list_len - function that returns the no. of list elements
 *
 * @h: head pointer to the first list element
 *
 * Return: The number of nodes in the list
 */
size_t list_len(const list_t *h)
{
	size_t n;

	n = 0;
	while (h != NULL)
	{
		n++;
		h = h->next;
	}

	return (n);
}
