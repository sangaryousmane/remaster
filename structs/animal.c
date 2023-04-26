#include <stdio.h>

struct Animal{
    char *name;
    char *type;
    double size;
};


void show(){
    struct Animal dog;
    struct Animal *ptr; // This is a pointer pointing at the struct Animal

    /* store the address of dog in the point ptr variable */
    ptr =&dog;

    /* De-Referencing the pointer values */
    ptr->name = "Catonie";
    ptr->size=4.2;
    (*ptr).type="Russian pillar";


    dog.size=5.5;
    dog.name="Poppy";
    dog.type="German dog";

    if (dog.size > 4){
        puts("This is a mature dog!");
    }

    printf("Size: %.2lf, Name: %s, Type: %s ", dog.size, dog.name, dog.type);
}