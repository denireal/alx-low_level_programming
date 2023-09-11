#include <stdio.h>
#include "dog.h"

/**
 * print_dog - Prints the name, age, and owner of a dog if they are not NULL.
 * @d: Pointer to the struct dog to be printed.
 *
 * Return: Nothing.
 */
void print_dog(struct dog *d)
{
	if (d == NULL)
		return;

	printf("Name: %s\n", (d->name != NULL) ? d->name : "(nil)");
	printf("Age: %.6f\n", d->age);
	printf("Owner: %s\n", (d->owner != NULL) ? d->owner : "(nil)");
}
