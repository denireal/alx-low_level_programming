#include "main.h"

/**
 * alloc_grid - program allocates a 2D grid of integers
 * and initializes to 0.
 * @width: width of the grid.
 * @height: height of the grid.
 *
 * Return: returns a pointer to the allocated grid, or NULL on failure.
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int i, j;

	if (width <= 0 || height <= 0)
	{
		return (NULL);
	}

	grid = (int **)malloc(height * sizeof(int *));

	if (grid == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < height; i++)
	{
		grid[i] = (int *)calloc(width, sizeof(int));
		if (grid[i] == NULL)
		{
			while (i >= 0)
			{
				free(grid[i]);
				i--;
			}
		free(grid);
		return (NULL);
		}
	}
	return (grid);
}
