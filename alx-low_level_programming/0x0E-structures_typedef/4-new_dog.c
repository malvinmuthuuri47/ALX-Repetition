#include "dog.h"

/**
 * _strlen - custom implementation of the strlen standard lib function
 *
 * @str: pointer to the memory address storing the pointer
 *
 * Return: length of the string
 */

int _strlen(char *str)
{
	int len;

	len = 0;
	while (str && str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcpy - custom implementation of the standard lib strcpy function
 *
 * @dest: the destination to copy the string to
 * @src: the source of the string
 *
 * Return: Pointer to the new memory address storing the string(destination)
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}


/**
 * new_dog - function that creates an instance of a struct
 * @name: the dog's name (string)
 * @age: the dog's age (float)
 * @owner: the dog's owner (string)
 *
 * Return: Pointer to the newly created struct instance
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int name_len, owner_len;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	name_len = _strlen(name);
	owner_len = _strlen(owner);

	d->name = malloc(name_len + 1);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = malloc(owner_len + 1);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	_strcpy(d->name, name);
	_strcpy(d->owner, owner);
	d->age = age;

	return (d);
}
