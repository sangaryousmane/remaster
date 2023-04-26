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

// Task 3
void print_dog(struct dog *d){

    if (d == NULL)
        printf("(nil)");
    if (d->name == NULL)
        printf("Name: (nil)");

    printf("Name: %s\n", d->name);
    printf("Age: %lf\n", d->age);
    printf("Owner: %s\n", d->owner);
}


int test(){
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    print_dog(&my_dog);
    return 0;
}