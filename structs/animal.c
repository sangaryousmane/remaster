#include <stdio.h>
#include <stdlib.h>

// TODO: DAY 14, structures in C.
// TODO: Implementing OOPs in C
typedef struct Animal {
    char *name;
    char *type;
    double age;
} access_animal;


access_animal *lion(char *name, char *type, double size) {
    access_animal *lion_type;

    /* Create and dynamically allocate space for the new struct */
    lion_type = malloc(sizeof(struct Animal));

    if (lion_type != NULL) {
        lion_type->age = size;
        lion_type->type = type;
        lion_type->name = name;
    }
    return lion_type;
}

int access_lion_func(){
    access_animal *lion_pointer;
    lion_pointer = (access_animal *) lion("Kimba",
                                          "Plagiarism Checker",
                                          .5);
    if (lion_pointer !=NULL){
        printf("Name is %s\n", lion_pointer->name);
        printf("Type is %s\n", lion_pointer->type);
        printf("KIMBA is %.1lf years old\n", lion_pointer->age);
    }
    return 1;
}

void show() {
    access_animal dog;

    dog.age = 5.5;
    dog.name = "Poppy";
    dog.type = "German dog";

    if (dog.age > 4) {
        puts("This is a mature dog!");
    }

    printf(
            "Size: %.2lf, Name: %s, Type: %s\n",
           dog.age, dog.name, dog.type);
}

void show_with_pointers() {
    access_lion_func();
    puts("Accessing structs through pointers: ");
    puts("-------------------------------------");
    struct Animal dog;
    struct Animal *ptr;
    // This is a pointer pointing at the struct Animal

    /* store the address of dog in the point ptr variable */
    ptr = &dog;

    /* De-Referencing the pointer values */
    (*ptr).name = "Catonie";
    (*ptr).age = 4.2;
    (*ptr).type = "Russian pillar";
    printf("Size: %.2lf, Name: %s, Type: %s ", ptr->age, ptr->name, ptr->type);

}
