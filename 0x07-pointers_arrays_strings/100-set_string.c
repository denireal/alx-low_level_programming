#include <stdio.h>
#include <string.h>

/**
 *  * set_string - Sets the value of a pointer to a char.
 *   * @s: Pointer to a pointer that will be set to a new string.
 *    * @to: Pointer to the string to be copied.
 *     */
void set_string(char **s, char *to)
{
	    if (*s != NULL)
		        {
				        for (int i = 0; (*s)[i] != '\0'; i++)
						        {
								            (*s)[i] = '\0';
									            }
					    }

	        for (int i = 0; to[i] != '\0'; i++)
			    {
				            (*s)[i] = to[i];
					        }
}
