#include "lists.h"

/**
 * free_list - frees memory allocated by malloc
 * @head: pointer to the first list node
 *
 * Return: void
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp->str);
		free(temp);
	}
}
