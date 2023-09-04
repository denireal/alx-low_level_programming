#include "main.h"

/**
 * free_grid - program frees a 2-dimensional grid of integers.
 * @grid: grid to be freed.
 * @height: number of rows in the grid.
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	/* Free individual rows and the array of pointers */
	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
