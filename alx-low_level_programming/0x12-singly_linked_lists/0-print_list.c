#include "lists.h"

/**
 * print_list - Traverses a linked list printing its elements
 * @h: pointer - Head pointer to the beginning of the list
 *
 * Return: The length of the list
 */

size_t print_list(const list_t *h)
{
	size_t n;

	n = 0;

	while (h != NULL)
	{
		if (h->str == NULL)
		{
			printf("[%u] (nil)\n", h->len);
		}
		else
		{
			printf("[%u] %s\n", h->len, h->str);
		}
		n++;
		h = h->next;
	}

	return (n);
}
