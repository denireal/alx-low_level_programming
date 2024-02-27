#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculates the perimeter of an island described in the grid.

    Args:
        grid (List[List[int]]): A 2D list representing the island grid.
            0 represents a water zone, and 1 represents a land zone.

    Returns:
        int: The perimeter of the island.

    Example:
        grid = [
            [0, 1, 0, 0],
            [1, 1, 1, 0],
            [0, 1, 0, 0],
            [1, 1, 0, 0]
        ]
        island_perimeter(grid)  # Output: 16
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
