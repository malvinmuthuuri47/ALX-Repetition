#include "main.h"

/**
 * is_prime_number - function that takes the num and a divisor and checks
 *                   whether num is divisible or not
 *
 * @num: the number passed from the is_prime function
 * @divisor: the number to test whether @num is prime or not
 *
 * Return: 1 if num is prime, 0 otherwise
 */

int is_prime_helper(int num, int divisor)
{
	if (divisor * divisor > num)
	{
		/* no divisor found, number is prime */
		return (1);
	}
	if (num % divisor == 0)
	{
		/* divisor found, number is prime */
		return (0);
	}
	return (is_prime_helper(num, divisor + 1));
}

/**
 * is_prime_number - function that checks if n is less greater than 1
 *                   and calls the recursive prime function
 * 
 * Return: 1 if n is prime, 0 otherwise
 */

int is_prime_number(int n)
{
	if (n <= 1)
	{
		return (0);
	}
	return (is_prime_helper(n, 2));
}
