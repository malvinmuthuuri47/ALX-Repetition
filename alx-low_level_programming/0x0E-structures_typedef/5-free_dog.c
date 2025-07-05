#include "dog.h"

/**
 * free_dog - function that frees dynamically allocated memory from a struct
 *
 * @d: pointer to the struct
 * Return: Nothing
 */

void free_dog(dog_t *d)
{
	free(d->owner);
	free(d->name);
	free(d);
}
