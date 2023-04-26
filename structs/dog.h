#include <stdio.h>
#include <stdlib.h>
#ifndef _DOG_
#define _DOG_

struct dog{
    char *name;
    char *owner;
    double age;
};

void init_dog(struct dog *d, char *name, double age, char *owner);
void print_dog(struct dog *d);
#endif /* _DOG_ */