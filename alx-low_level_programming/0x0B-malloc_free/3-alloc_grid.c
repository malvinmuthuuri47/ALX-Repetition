#include "main.h"

#define invalid_input 1
#define my_null_pointer ((void *)0)

/**
 * alloc_grid - function that takes width and height and creates a 2D array
 *
 * @width: the width or the columns
 * @height: the height or the rows
 *
 * Return: an integer pointer to the 2D array populated with 0
 */
int **alloc_grid(int width, int height)
{
	int **arr;
	int i, j, k;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	arr = malloc(height * sizeof(int *));
	if (arr == NULL)
	{
		return (my_null_pointer);
	}

	for (i = 0; i < height; i++)
	{
		arr[i] = malloc(width * sizeof(int));
		if (arr[i] == NULL)
		{
			for (k = 0; k < i; k++)
			{
				free(arr[k]);
			}
			free(arr);
			return (my_null_pointer);
		}

		for (j = 0; j < width; j++)
		{
			arr[i][j] = 0;
		}
	}

	return (arr);
}
