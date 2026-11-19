#include "lists.h"

/**
 * sum_listint - function that cumulatively adds the n in each node of the list
 *
 * @head: pointer to the first node in the list
 *
 * Return: the cumulative score, 0 otherwise
 */
int sum_listint(listint_t *head)
{
	int i;

	i = 0;
	while (head != NULL)
	{
		i += head->n;
		head = head->next;
	}

	return (i);
}
