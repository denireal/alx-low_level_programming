#ifndef DOG_H
#define DOG_H
/**
 * struct dog - the struct called dog
 * @name: pointer to a character array representing the name of the dog.
 * @age: floating-point number representing the age of the dog.
 * @owner: pointer to a character array representing the name of the dog's owner
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

/* other task prototypes */
void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strncpy(char *dest, char *src, int n);
int _strlen(char *s);

#endif
