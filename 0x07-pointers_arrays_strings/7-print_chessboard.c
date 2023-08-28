/**
* print_chessboard - Display the contents of a chessboard.
* @a: A two-dimensional array representing the chessboard.
*
* This function prints the contents of the given two-dimensional
* array, which represents a chessboard, row by row. Each element
* of the array corresponds to a square on the chessboard.
*
* Return: void
*/
void print_chessboard(char (*a)[8])
{
	int i = 0, j;

	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			_putchar(*(*(a + i) + j));
			j++;
		}
		_putchar('\n');
		i++;
	}
}
