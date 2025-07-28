#include "3-calc.h"

/**
 * op_add - function that takes two parameters and returns their sum
 *
 * @a: param1
 * @b: param2
 *
 * Return: The sum of the two params
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - function that takes two parameters and returns their difference
 *
 * @a: param1
 * @b: param2
 *
 * Return: The difference of the two params
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - function that takes two params and returns their product
 *
 * @a: param1
 * @b: param2
 *
 * Return: The product of the two params
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - function that takes two params and returns the division quotient
 *
 * @a: param1
 * @b: param2
 *
 * Return: The quotient of the division
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - function that returns the remainder of division of two params
 *
 * @a: param1
 * @b: param2
 *
 * Return: The remainder of the division
 */
int op_mod(int a, int b)
{
	return (a % b);
}
