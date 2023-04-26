#include <stdio.h>
#include <stdlib.h>

struct Animal {
    char *name;
    char *type;
    double size;
};

struct Animal *lion(char *name, char *type, double size) {
    struct Animal *lion_type;

    /* Dynamically allocate space for the new struct */
    lion_type = malloc(sizeof(struct Animal));

    if (lion_type != NULL) {
        lion_type->size = size;
        lion_type->type = type;
        lion_type->name = name;
    }
    return lion_type;
}


void show() {
    struct Animal dog;

    dog.size = 5.5;
    dog.name = "Poppy";
    dog.type = "German dog";

    if (dog.size > 4) {
        puts("This is a mature dog!");
    }

    printf("Size: %.2lf, Name: %s, Type: %s\n", dog.size, dog.name, dog.type);
}

void show_with_pointers() {

    puts("Accessing structs through pointers: ");
    puts("-------------------------------------");
    struct Animal dog;
    struct Animal *ptr;
    // This is a pointer pointing at the struct Animal

    /* store the address of dog in the point ptr variable */
    ptr = &dog;

    /* De-Referencing the pointer values */
    (*ptr).name = "Catonie";
    (*ptr).size = 4.2;
    (*ptr).type = "Russian pillar";
    printf("Size: %.2lf, Name: %s, Type: %s ", ptr->size, ptr->name, ptr->type);

}
