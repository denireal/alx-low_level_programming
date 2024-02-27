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
    perimeter = 0
    # Iterate over each cell in the grid
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:  # If the cell is land
                perimeter += 4  # Increment perimeter by 4 for each land cell
                # Check adjacent cells to the top and left
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Subtract 2 if there's land to the top
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Subtract 2 if there's land to the left
    return perimeter
