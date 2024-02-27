#!/usr/bin/python3

"""
This function calculates the perimeter of an island represented by a 2D grid.
The grid consists of 0s representing water and 1s representing land. The perimeter
is the length of the boundary between land and water.

Args:
    grid (List[List[int]]): A 2D list representing the island grid.

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

def island_perimeter(grid):
    perimeter = 0
    
    # Iterate over each cell in the grid
    for y, row in enumerate(grid):
        for x, cell in enumerate(row):
            if cell == 1:  # If the cell represents land
                # Check neighbors to determine if the edge is exposed to water
                # If at the boundary or neighbor is water, increment perimeter
                if y == 0 or grid[y - 1][x] == 0:
                    perimeter += 1
                if y == len(grid) - 1 or grid[y + 1][x] == 0:
                    perimeter += 1
                if x == 0 or grid[y][x - 1] == 0:
                    perimeter += 1
                if x == len(row) - 1 or grid[y][x + 1] == 0:
                    perimeter += 1

    return perimeter
