#include "lists.h"

/**
 * add_nodeint - function that adds a node at the beginning of a list
 *
 * @head: pointer to head pointer
 * @n: int value for required by the struct
 *
 * Return: Pointer to the newly created node
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node;

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

	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
