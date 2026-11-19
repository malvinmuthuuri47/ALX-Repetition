#include "lists.h"

/**
 * find_listint_loop - function that finds the beginning of a loop
 * in a cyclic linked list using the floyd cyclic algorithm
 *
 * @head: pointer to the beginning of the list
 *
 * Return: Address of the node at which the cycle begins, NULL otherwise
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow;
	listint_t *fast;

	slow = head;
	fast = head;

	/* Detect a cycle */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			/* Find the cycle entry */
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			return (slow);
		}
	}

	return (NULL);
}
