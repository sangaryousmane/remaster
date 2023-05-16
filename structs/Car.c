#include <stdio.h>

// TODO: Day 16, C marathon. struct continues
struct Car {
    char *brand;
    char *name;
    double price;
};

typedef struct Car BMW;

void access_bmw(){
    BMW bmw;

    bmw.name = "BMW X4";
    bmw.brand = "BMW";
    bmw.price = 65000.00;
    printf("Name: %s\n", bmw.name);
    printf("Brand: %s\n", bmw.brand);
    printf("Price: %.2lf", bmw.price);
}