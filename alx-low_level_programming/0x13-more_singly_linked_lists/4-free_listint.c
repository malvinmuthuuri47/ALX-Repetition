#include "lists.h"

/**
 * free_listint - function that frees the memory allocated to each node
 *
 * @head: pointer to the first node in the list
 *
 */
void free_listint(listint_t *head)
{
	listint_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
