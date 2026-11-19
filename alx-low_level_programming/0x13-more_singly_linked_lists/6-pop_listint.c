#include "lists.h"

/**
 * pop_listint - function that deletes the head node of a linked list
 *
 * @head: pointer to the head pointer
 *
 * Return: head node's data, 0 otherwise
 */
int pop_listint(listint_t **head)
{
	listint_t *temp;
	int score;

	if (head == NULL || *head == NULL)
	{
		return (0);
	}

	temp = *head;
	score = temp->n;
	*head  = temp->next;
	free(temp);
	return (score);
}
