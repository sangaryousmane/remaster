#include <stdio.h>
#include <stdlib.h>
#ifndef _DOG_
#define _DOG_

struct dog{
    char *name;
    char *owner;
    double age;
};
typedef struct dog dog_t;
void init_dog(struct dog *d, char *name, double age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
#endif /* _DOG_ */