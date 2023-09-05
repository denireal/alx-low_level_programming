#include "main.h"

/**
 * get_wds_ct - counts the number of words in a string
 * @str: input string
 *
 * Return: The number of words in the string.
 */
int get_wds_ct(char *str)
{
int ct = 0;
int in_wd = 0;

while (*str)
{
if (*str == ' ' || *str == '\t' || *str == '\n')
{
in_wd = 0;
}
else if (in_wd == 0)
{
ct++;
in_wd = 1;
}
str++;
}
return (ct);
}

/**
 * strtow - splits a given string into words
 * @str: the string
 *
 * Return: the pointer to the string array or NULL
 */
char **strtow(char *str)
{
int wds_ct;
int wd_len;
char **wds;
int i = 0;
int j = 0;
char *wd_s;

if (str == NULL || *str == '\0')
return (NULL);

wds_ct = get_wds_ct(str);
if (wds_ct == 0)
return (NULL);

wds = malloc((wds_ct + 1) * sizeof(char *));
if (wds == NULL)
return (NULL);

while (*str)
{
if (*str == ' ' || *str == '\t' || *str == '\n')
{
str++;
}
else
{
wd_s = str;
while (*str && *str != ' '
&& *str != '\t' && *str != '\n')
str++;
wd_len = str - wd_s;
wds[i] = malloc((wd_len + 1) * sizeof(char));
if (wds[i] == NULL)
{
for (; j < i; j++)
{
free(wds[j]);
}
free(wds);
return (NULL);
}
strncpy(wds[i], wd_s, wd_len);
wds[i][wd_len] = '\0';
i++;
}
}
wds[i] = NULL;
return (wds);
}
