#include "dog.h"

/**
 * init_dog - function that initializes a struct using its params
 *
 * @d: Pointer to the struct memory address
 * @name: the dog name
 * @age: the dog age
 * @owner: the dog owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
