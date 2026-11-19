#include "lists.h"

/**
 * free_listint2 - function that frees the memory address pointed to
 * by the double head pointer
 *
 * @head: pointer to the head pointer
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	while (*head != NULL)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
	*head = NULL;
}
