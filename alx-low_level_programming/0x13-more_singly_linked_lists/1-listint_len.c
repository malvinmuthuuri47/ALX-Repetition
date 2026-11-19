#include "lists.h"

/**
 * listint_len - function that returns the no. of nodes in a list
 *
 * @h: head pointer
 *
 * Return: len of list
 */
size_t listint_len(const listint_t *h)
{
	size_t i;

	i = 0;
	while (h != NULL)
	{
		++i;
		h = h->next;
	}

	return (i);
}
