#include "function_pointers.h"

/**
 * print_name - function that takes a pointer to a string and a function and
 * uses the function to print the name
 *
 * @name: pointer to the string (name)
 * @f: pointer to the function that prints the name
 *
 * Return: Nothing
 */

void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
