/**
 * reverse_array - function to reverse an array of integers
 * @a: the input array
 * @n: number of array elements
 *
 * Return: will return void
 */
void reverse_array(int *a, int n)
{
	int count = 0;
	int temp;

	while (count < n--)
	{
		temp = a[count];
		a[count++] = a[n];
		a[n] = temp;
	}
}
