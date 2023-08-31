#include "main.h"
#include <stdbool.h>

int memo[MAX_LEN][MAX_LEN];

int wildcmp_helper(char *s1, char *s2, int len1, int len2);
/**
 * wildcmp - Compare two strings with wildcards
 * @s1: First string
 * @s2: Second string
 *
 * Return: 1 if strings match, 0 otherwise
 */

int wildcmp(char *s1, char *s2)
{
	int i = 0, j = 0;

	if (i < MAX_LEN)
	{
		if (j < MAX_LEN)
		{
			memo[i][j] = -1;
			j++;
			return (wildcmp(s1, s2));
		}
		i++;
		j = 0;
		return (wildcmp(s1, s2));
	}
	return (wildcmp_helper(s1, s2, 0, 0));
}
/**
 * wildcmp_helper - Helper function for comparing strings with wildcards
 * @s1: First string
 * @s2: Second string
 * @len1: Current position in s1
 * @len2: Current position in s2
 *
 * Return: 1 if strings match, 0 otherwise
 */
int wildcmp_helper(char *s1, char *s2, int len1, int len2)
{
	int result1, result2, result3;

	if (memo[len1][len2] != -1)
		return (memo[len1][len2]);

	if (s1[len1] == '\0' && s2[len2] == '\0')
		return (memo[len1][len2] = 1);

	if (s1[len1] == s2[len2] || s1[len1] == '*' || s2[len2] == '*')
	{
		result1 = wildcmp_helper(s1, s2, len1 + 1, len2 + 1);
		result2 = wildcmp_helper(s1, s2, len1 + 1, len2);
		result3 = wildcmp_helper(s1, s2, len1, len2 + 1);

		if (result1 || result2 || result3)
			return (memo[len1][len2] = 1);
	}
	return (memo[len1][len2] = 0);
}
