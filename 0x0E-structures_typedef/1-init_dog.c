#include "dog.h"
#include <stdlib.h>
#include <string.h>

/**
 * init_dog - initializes a variable of type struct dog.
 * @d: pointer to the struct
 * @name: name of the dog
 * @age: age of the dog
 * @owner: pointer to owner of the dog
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
	{
		return;
	}

	d->name = strdup(name);
	if (d->name == NULL)
	{
		return;
	}

	d->age = age;
	d->owner = strdup(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		return;
	}
}
