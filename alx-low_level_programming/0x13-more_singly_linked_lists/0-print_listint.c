#include "lists.h"

/**
 * print_listint - function that traverses a list and prints its elements
 *
 * @h: head pointer
 *
 * Return: The length of the list
 */
size_t print_listint(const listint_t *h)
{
	size_t i;

	i = 0;
	while (h != NULL)
	{
		printf("%d\n", h->n);
		i++;
		h = h->next;
	}

	return (i);
}
