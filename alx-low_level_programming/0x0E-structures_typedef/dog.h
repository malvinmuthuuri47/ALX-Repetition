#ifndef DOG_H
#define DOG_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct dog - a struct that combines attributes of a dog together
 *
 * @name: A string indicating the name of the dog
 * @age: An integer indicating the age of the dog
 * @owner: A string indicating the dog owner
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
int _strlen(char *str);
char *_strcpy(char *dest, char *src);
void free_dog(dog_t *d);

#endif
