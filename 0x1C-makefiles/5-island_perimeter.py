#!/usr/bin/python3
"""Defines a function to calculate the perimeter of an island."""



def island_perimeter(grid):
    """Calculate the perimeter of an island represented by a grid.

    Args:
        grid (list): A list of lists representing the island grid where:
                     - Each sublist represents a row of the grid.
                     - Each element of the sublist is an integer, 0 or 1,
                       representing water (0) or land (1) respectively.

    Returns:
        int: The perimeter of the island.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                if j > 0 and grid[i][j - 1] == 1:
                    edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edges += 1
    return sum(sum(row) for row in grid) * 4 - edges * 2
