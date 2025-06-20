#include "main.h"

/**
 * is_space - function that determines if the current character is a delimiter
 *
 * @c: the character to be checked if its a delimiter(space, new line, or tab
 *
 * Return: 1 if delimiter, 0 otherwise
 */
int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/**
 * word_count - function that calculates the length of the string passed to it
 *
 * @str: pointer to the string
 *
 * Return: the length of the string
 */
int word_count(char *str)
{
	int count, in_word, i;

	count = 0;
	in_word = 0;
	i = 0;

	while (str[i] != '\0')
	{
		if (!is_space(str[i]) && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (is_space(str[i]))
		{
			in_word = 0;
		}
		i++;
	}

	return (count);
}

/**
 * copy_word - a function that copies a string to a new memory address
 * starting from the start demarcated by the start param upto the length
 *
 * @str: pointer to the string to be copied
 * @start: the begininning of the string
 * @length: the size of the string to copy
 *
 * Return: A pointer to the new memory address where the new string is stored
 */
char *copy_word(char *str, int start, int length)
{
	char *word;
	int i;

	word = malloc((length + 1) * sizeof(char));
	if (word == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < length; i++)
	{
		word[i] = str[start + i];
	}
	word[length] = '\0';

	return (word);
}

/**
 * free_words - function that frees previously allocated memory if an error
 * occurs before the complete memory allocation is done
 *
 * @words: the array of strings to allocate memory to
 * @count: number of words that were successfully allocated
 *
 * Return: Nothing
 */
void free_words(char **words, int count)
{
	while (--count >= 0)
	{
		free(words[count]);
	}
	free(words);
}

/**
 * strtow - function that takes a string and splits it into individual words
 * based on the delimiters in the is_space helper function
 *
 * @str: the pointer to the string
 *
 * Return: words of the original string separated by a newline
 */
char **strtow(char *str)
{
	int i, w, start, len, total;
	char **words;

	i = 0;
	w = 0;
	start = 0;
	len = 0;
	total = 0;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	total = word_count(str);
	if (total == 0)
		return (NULL);

	words = malloc((total + 1) * sizeof(char *));
	if (!words)
		return (NULL);

	while (str[i])
	{
		if (!is_space(str[i]))
		{
			start = i, len = 0;
			while (str[i] && !is_space(str[i]))
				len++, i++;
			words[w] = copy_word(str, start, len);
			if (!words[w])
			{
				free_words(words, w);
				return (NULL);
			}
			w++;
		}
		else
			i++;
	}
	words[w] = NULL;
	return (words);
}
