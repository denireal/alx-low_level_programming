/**
 * _isalpha - Program checks whether given character is lowercase
 * @c: The character to be checked
 *
 * Return: bool_value either 1 or 0
 */
int _isalpha(int c)
{
	char uppercase_alpha, lowercase_alpha;
	int bool_value = 0;

	lowercase_alpha = 'a';

	while (lowercase_alpha <= 'z')
	{
		uppercase_alpha = 'A';
		while (uppercase_alpha <= 'Z')
		{
			if (c == lowercase_alpha || c == uppercase_alpha)
			{
				bool_value = 1;
				uppercase_alpha++;
			}
		}
		lowercase_alpha++;
	}
	return (bool_value);
}
