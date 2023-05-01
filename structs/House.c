#include <stdio.h>

// TODO: DAY 17, struct in C continue
// TODO: implementing object orientation in C
struct House {
    int num_rooms;
    double lot_size;
    char *address;
};

int displayHouseInfo() {
    struct House my_house;

    my_house.num_rooms = 3;
    my_house.lot_size = 0.25;
    my_house.address  = "123 Main St";

    printf("\nHOUSE DETAILS:\n");
    printf("My house has %d rooms\n", my_house.num_rooms);
    printf("a lot size of %.2f acres, \n", my_house.lot_size);
    printf("and is located at %s.\n", my_house.address);
    return 0;
}