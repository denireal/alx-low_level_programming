#include "main.h"

/**
 * get_words_count - counts the number of words in a string
 * @str: input string
 *
 * Return: The number of words in the string.
 */
int get_words_count(char *str)
{
	int count = 0;
	int in_word = 0;

	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			in_word = 0;
		}
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
		str++;
	}
	return (count);
}

/**
 * strtow - splits a given string into words
 * @str: the string
 *
 * Return: the pointer to the string array or NULL
 */
char **strtow(char *str)
{
	int words_count;
	int word_length;
	char ** words;
	int i = 0;
	int j = 0;
	char *word_start;

	if (str == NULL || *str == '\0')
		return (NULL);

	words_count = get_words_count(str);
	if (words_count == 0)
		return (NULL);

	words = malloc((words_count + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);

	while (*str)
	{
		if (*str == ' ' || *str == '\t' || *str == '\n')
		{
			str++;
		}
		else
		{
			word_start = str;
while (*str && *str != ' ' &&
		*str != '\t' && *str != '\n')
				str++;
			word_length = str - word_start;
words[i] = malloc((word_length + 1) * sizeof(char));
			if (words[i] == NULL)
			{
				for (; j < i; j++)
				{
					free(words[j]);
				}
				free(words);
				return (NULL);
			}
strncpy(words[i], word_start, word_length);
words[i][word_length] = '\0';
			i++;
		}
	}
	words[i] = NULL;
	return (words);
}
