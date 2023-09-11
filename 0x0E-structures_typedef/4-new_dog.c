#include <stdlib.h>
#include "dog.h"

/**
 * new_dog - creates a new dog with initialized values
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to a new dog, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	unsigned int name_length, owner_length, i;
	dog_t *dog;

	if (name == NULL || owner == NULL)
		return (NULL);

	/* Allocate memory for the dog struct */
	dog = malloc(sizeof(dog_t));
	if (dog == NULL)
		return (NULL);

	/* Compute the length of the name and allocate memory for it */
	for (name_length = 0; name[name_length]; name_length++)
		;
	name_length++;
	dog->name = malloc(name_length * sizeof(char));
	if (dog->name == NULL)
	{
		free(dog);
		return (NULL);
	}

	/* Copy the name to the dog's name member */
	for (i = 0; i < name_length; i++)
		dog->name[i] = name[i];
	dog->age = age;

	/* Compute the length of the owner and allocate memory for it */
	for (owner_length = 0; owner[owner_length]; owner_length++)
		;
	owner_length++;
	dog->owner = malloc(owner_length * sizeof(char));

	if (dog->owner == NULL)
	{
		free(dog->name);
		free(dog);
		return (NULL);
	}

	/* Copy the owner to the dog's owner member */
	for (i = 0; i < owner_length; i++)
		dog->owner[i] = owner[i];
	return (dog);
}
