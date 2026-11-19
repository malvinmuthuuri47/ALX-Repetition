#include "lists.h"

/**
 * find_cycle_start - uses floyd cycle detection algorithm to detect
 * a cycle in a linked list
 *
 * @head: pointer to the first node in the list
 *
 * Return: pointer to the cycle's entry node, NULL otherwise
 */
const listint_t *find_cycle_start(const listint_t *head)
{
	const listint_t *slow;
	const listint_t *fast;

	slow = head;
	fast = head;

	/* Detect a cycle */
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (slow == fast)
		{
			break;
		}
	}

	/* No cycle found */
	if (fast == NULL || fast->next == NULL)
	{
		return (NULL);
	}

	/* Find the beginning of the cycle */
	slow = head;

	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}


/**
 * print_until - prints the node's content till a stopping condition
 *
 * @start: the starting traversal node
 * @stop: the stopping traversal node
 *
 * Return: number of nodes printed.
 */
size_t print_until(const listint_t *start, const listint_t *stop)
{
	size_t count;

	count = 0;
	while (start != stop)
	{
		printf("[%p] %d\n", (void *)start, start->n);
		start = start->next;
		count++;
	}

	return (count);
}

/**
 * print_cycle - prints nodes in the cycle
 *
 * @cycle_start: starting node of the cycle
 *
 * Return: number of nodes printed
 */
size_t print_cycle(const listint_t *cycle_start)
{
	const listint_t *current;
	size_t count;

	count = 0;
	current = cycle_start;

	do {
		printf("[%p] %d\n", (void *)current, current->n);
		current = current->next;
		count++;
	} while (current != cycle_start);

	return (count);
}

/**
 * print_listint_safe - prints the list by calling the helpers above
 *
 * @head: pointer to the first node in the list
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *cycle_start;
	size_t count;

	count = 0;
	cycle_start = find_cycle_start(head);

	if (cycle_start != NULL)
	{
		count += print_until(head, cycle_start);
		count += print_cycle(cycle_start);
	}
	else
	{
		count = print_until(head, NULL);
	}

	return (count);
}
