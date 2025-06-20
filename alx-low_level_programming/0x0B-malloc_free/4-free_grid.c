#include "main.h"

/**
 * free_grid - function that frees memory allocated on the heap in a 2D grid
 *
 * @grid: pointer to the 2D array
 * @height: the rows of the 2D array
 *
 * Return: Nothing
 */

void free_grid(int **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
