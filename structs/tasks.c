#include <stdio.h>
#include <stdlib.h>

#include "dog.h"

// Task 2
void init_dog(struct dog *d, char *name, double age, char *owner) {


    if (d != NULL) {
        d->name = name;
        d->age = age;
        d->owner = owner;
    }
}

// Task 3
void print_dog(struct dog *d) {


    if (d != NULL) {
        if (d->owner == NULL ) {
            printf("Owner: (nil)\n");
        }
        if (d->age <= .0){
            printf("Age: (nil)\n");
        }
        if (d->name == NULL) {
            printf("Name: (nil)\n");
        } else {
            printf("Name: %s\n", d->name);
            printf("Age: %lf\n", d->age);
            printf("Owner: %s\n", d->owner);
        }
    }
}


int test() {
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    print_dog(&my_dog);
    print_dog(NULL);
    return 0;
}