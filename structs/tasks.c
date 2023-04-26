#include <stdio.h>
#include <stdlib.h>

#include "dog.h"

// Task 2
void init_dog(struct dog *d, char *name, double age, char *owner){


    if (d !=NULL){
        d->name=name;
        d->age=age;
        d->owner=owner;
    }
}

int test(){
    struct dog my_dog;

    init_dog(&my_dog, "Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return 0;
}