#include <stdio.h>
#include <stdlib.h>

// TODO: DAY 18, struct in C continue
// TODO: implementing object orientation in C
struct House {
    int num_rooms;
    double lot_size;
    char *address;
};
typedef struct House house_type;

// TODO: struct in C, mimicking Object orientation in C
// TODO: creating many types of house from one one blue print
house_type *new_type(int num_rooms, double lot_size, char *address) {

    house_type *apartment;
    apartment = malloc(sizeof(house_type));

    if (apartment != NULL) {
        apartment->address = address;
        apartment->lot_size = lot_size;
        apartment->num_rooms = num_rooms;
    }
    return apartment;
}

void displayHouseInfo() {
    house_type *apartment, *skyscraper;
    apartment = new_type(4, 1, "NYK");
    skyscraper = new_type(10, 4, "Hongkong");

    printf("\nHOUSE DETAILS:\n");
    printf("My house has %d rooms\n", apartment->num_rooms);
    printf("a lot size of %.2f acres, \n", apartment->lot_size);
    printf("and is located at %s.\n", apartment->address);

    printf("\nHOUSE DETAILS:\n");
    printf("My house has %d rooms\n", skyscraper->num_rooms);
    printf("a lot size of %.2f acres, \n", skyscraper->lot_size);
    printf("and is located at %s.\n", skyscraper->address);
}