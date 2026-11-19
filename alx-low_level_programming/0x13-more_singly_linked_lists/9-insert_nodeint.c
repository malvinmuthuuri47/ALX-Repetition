#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a node at a specified index in a list
 *
 * @head: pointer to the head pointer
 * @idx: the specified position to insert the node
 * @n: value to insert to the new node
 *
 * Return: the address of the new node, NULL otherwise
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node;
	listint_t *previous;
	size_t i;

	if (head == NULL)
	{
		return (NULL);
	}
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
	{
		return (NULL);
	}
	new_node->n = n;
	new_node->next = NULL;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	previous = *head;
	i = 0;
	while (previous != NULL && i < idx - 1)
	{
		previous = previous->next;
		i++;
	}

	if (previous == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = previous->next;
	previous->next = new_node;
	return (new_node);
}
