#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node at a specified index
 *
 * @head: pointer to the head pointer
 * @index: the index of the node to delete
 *
 * Return: 1 if deleted successfully, 0 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp;
	listint_t *previous;
	unsigned int i;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	if (index == 0)
	{
		temp = *head;
		*head = temp->next;
		free(temp);
		return (1);
	}

	previous = *head;
	i = 0;

	while (previous != NULL && i < index - 1)
	{
		previous = previous->next;
		i++;
	}
	if (previous == NULL || previous->next == NULL)
	{
		return (-1);
	}
	temp = previous->next;
	previous->next = temp->next;
	free(temp);

	return (1);
}
