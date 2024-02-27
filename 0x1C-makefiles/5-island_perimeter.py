#!/usr/bin/python3

def island_perimeter(grid):
    """
    Calculates the perimeter of an island represented by a 2D grid.
    
    Args:
        grid (List[List[int]]): A 2D list representing the island grid.
            1 represents land, 0 represents water.
    
    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:  # Check if the cell is land
                perimeter += 4
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2  # Subtract 2 if there's land to the top
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2  # Subtract 2 if there's land to the left
    return perimeter
