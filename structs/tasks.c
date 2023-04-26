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

// Task 4
dog_t *new_dog(char *name, float age, char *owner){
    dog_t *dog;
    dog = malloc(sizeof(dog_t));

    if (dog==NULL)
        return NULL;

    dog->name=name;
    dog->owner=owner;
    dog->age=age;
    return dog;
}
int test() {
    dog_t *my_dog;

    my_dog = new_dog("Poppy", 3.5, "Bob");
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog->name, my_dog->age);
    return 0;
}