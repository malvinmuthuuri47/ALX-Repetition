#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - function that takes an arithmetic sign and returns a pointer
 * to the function that performs the arithmetic operation associated with
 * the sign
 *
 * @s: the arithmetic sign corresponding to the arithmetic operation
 *
 * Return: A pointer to the function that performs the specified arithmetic
 * operation
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i;

	i = 0;
	while (ops[i].op)
	{
		if (*ops[i].op == *s && s[1] == '\0')
			return (ops[i].f);
		i++;
	}
	return (NULL);
}
