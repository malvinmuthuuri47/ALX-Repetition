#include "dog.h"

/**
 * print_dog - A function that prints the content of the struct passed to it
 *
 * @d: pointer to the struct address in memory
 */

void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", d->name ? d->name : "(nil)");
	printf("Age: %f\n", d->age);
	printf("Owner: %s\n", d->owner ? d->owner : "(nil)");
}
