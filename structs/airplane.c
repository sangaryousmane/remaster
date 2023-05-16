#include <stdio.h>


// TODO: struct in C, Mimicking an Airplane
struct airplane {
    char *model;
    int capacity;
    int num_passengers;
};

int show_airplane() {
    struct airplane my_airplane = {"Boeing 747",
            416, 0};

    printf("Model: %s\n", my_airplane.model);
    printf("Capacity: %d\n", my_airplane.capacity);
    printf("Number of passengers: %d\n", my_airplane.num_passengers);

    return 0;
}
