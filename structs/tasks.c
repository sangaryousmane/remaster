#include <stdio.h>
#include <stdlib.h>

#include "dog.h"

// Task 1

int test(){
    struct dog my_dog;

    my_dog.name = "Poppy";
    my_dog.age = 3.5;
    my_dog.owner = "Bob";
    printf("My name is %s, and I am %.1f :) - Woof!\n", my_dog.name, my_dog.age);
    return 0;
}