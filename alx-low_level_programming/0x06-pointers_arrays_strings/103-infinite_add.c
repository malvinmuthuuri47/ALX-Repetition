#include "main.h"

/**
 * get_length - helper function to calculate the length of a string
 * @str: pointer to the string
 *
 * Return: The string length
 */

int get_length(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * add_digits - function that adds the characters in a string
 *
 * @digit1: the first digit to add
 * @digit2: the second digit to add
 * @carry: the carry over resulting from the addition
 * @result: the buffer that stores the final addition values
 *
 * Return: the carry over value
 */

int add_digits(int digit1, int digit2, int carry, char *result)
{
	int sum;

	sum = digit1 + digit2 + carry;
	*result = (sum % 10) + '0';
	return (sum / 10);
}

/**
 * shift_result - Function that shifts the order of the results
 * in the buffer
 *
 * @r: the buffer
 * @k: the position inside the buffer
 *
 * Return: void
 */

void shift_result(char *r, int k)
{
	int i;

	i = 0;
	k++;
	while (r[k] != '\0')
	{
		r[i++] = r[k++];
	}
	r[i] = '\0';
}

/**
 * infinite_add - main function that adds the string characters as nums
 * @n1: the pointer to the first character array
 * @n2: the pointer to the second character array
 * @r: the buffer
 * @size_r: the buffer size
 *
 * Return: A pointer to the results of the addition
 */

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, carry, i, j, k, digit1, digit2;

	len1 = get_length(n1);
	len2 = get_length(n2);

	k = size_r - 2;
	r[size_r - 1] = '\0';

	i = len1 - 1;
	j = len2 - 1;
	carry = 0;

	while (i >= 0 || j >= 0 || carry != 0)
	{
		if (k < 0)
		{
			return (0);
		}

		digit1 = (i >= 0) ? (n1[i--] - '0') : 0;
		digit2 = (j >= 0) ? (n2[j--] - '0') : 0;

		carry = add_digits(digit1, digit2, carry, &r[k--]);
	}

	if (carry != 0 && k < 0)
	{
		return (0);
	}

	if (carry != 0)
	{
		r[k--] = carry + '0';
	}

	shift_result(r, k);
	return (r);
}
