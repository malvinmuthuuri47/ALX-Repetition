#include "lists.h"

/**
 * find_cycle_start_2 - Floyd's cycle detection algorithm function
 *
 * @head: pointer to the first node
 *
 * Return: A pointer to the cycle's entry node if a cycle exists
 */
listint_t *find_cycle_start_2(listint_t *head)
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

/**
 * break_cycle - traverses the cyclic list and points last node to NULL
 *
 * @cycle_start: pointer to where the cycle beings
 *
 * Return: None
 */
void break_cycle(listint_t *cycle_start)
{
	listint_t *last;

	last = cycle_start;
	while (last->next != cycle_start)
		last = last->next;

	last->next = NULL;
}

/**
 * free_listint_t - helper func containing the free list logic
 *
 * @head: pointer to the first node
 *
 * Return: the number of nodes freed
 */
size_t free_listint_t(listint_t *head)
{
	listint_t *current;
	listint_t *next;
	size_t count;

	count = 0;
	current = head;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
		count++;
	}

	return (count);
}

/**
 * free_listint_safe - frees a circular or ordinary linked list
 *
 * @h: pointer to the head pointer
 *
 * Return: The number of nodes in the list
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *cycle_start;
	size_t count;

	if (h == NULL || *h == NULL)
		return (0);

	cycle_start = find_cycle_start_2(*h);

	if (cycle_start != NULL)
		break_cycle(cycle_start);

	count = free_listint_t(*h);
	*h = NULL;

	return (count);
}
