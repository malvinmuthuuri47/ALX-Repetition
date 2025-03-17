#include "main.h"

/**
 * binary_search_sqrt - helper function that finds the square root
 *                      of a number using a binary search algorithm
 *
 * @num: the number to look for the squareroot
 * @low: the lower bound to search for the squareroot
 * @high: the upper bound to search for the square root
 *
 * Return: the square root of num, -1 otherwise
 */

int binary_search_sqrt(int num, int low, int high)
{
	int mid;

	if (low > high)
	{
		/* no perfect square root found */
		return (-1);
	}

	/* find the midpoint */
	mid = (low + high) / 2;

	/* check if mid is the perfect square root of num */
	if (mid * mid == num)
	{
		/* perfect square root found */
		return (mid);
	}

	/* adjust the range */
	if (mid * mid < num)
	{
		/* search upper half */
		return (binary_search_sqrt(num, mid + 1, high));
	}
	else
	{
		return (binary_search_sqrt(num, low, mid - 1));
	}
}

/**
 * _sqrt_recursion - main function to call the binary_sqrt helper
 *
 * @n: the integer to search the squareroot
 *
 * Return: the found squaareroot integer from the binary_search helper
 */

int _sqrt_recursion(int n)
{
	/* handle special cases */
	if (n < 0)
	{
		return (-1);
	}
	else if (n == 0 || n == 1)
	{
		return (n);
	}
	else
	{
		return (binary_search_sqrt(n, 0, n));
	}
}
