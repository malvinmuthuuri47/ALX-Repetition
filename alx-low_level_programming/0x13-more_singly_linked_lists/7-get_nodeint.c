#include "lists.h"

/**
 * get_nodeint_at_index - returns a node at a specified index in a list
 *
 * @head: head pointer to list
 * @index: position to check against the node
 *
 * Return: node at the specified position, NULL otherwise
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;

	i = 0;
	while (head != NULL)
	{
		if (i == index)
		{
			return (head);
		}
		head = head->next;
		i++;
	}
	return (NULL);
}
