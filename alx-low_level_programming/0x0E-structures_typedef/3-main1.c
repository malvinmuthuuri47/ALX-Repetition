#include <stdio.h>
#include "dog.h"

/**
 * main - check the code .
 *
 * Return: Always 0.
 */
int main(void)
{
#ifdef dog_t
	printf("'dog_t' should not be a #define !\n");
	return (0);
#else
	dog_t my_dog;

	my_dog.name = "Ghost";
	my_dog.age = 4.75;
	my_dog.owner = "Jon Snow";
	printf("My name is %s, I am %.2f, and my owner is %s\n",
		my_dog.name, my_dog.age, my_dog.owner);
	return (0);
#endif
}
