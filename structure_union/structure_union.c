/*
Author: chankruze (chankruze@geekofia.in)
Created: Thu Jan 07 2021 17:56:59 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include <stdio.h>

#include "../libs/chankruze.h"

// declaration
struct Person {
    char *name;
    int age;
    double height;
};

union Nation {
    char *name;
    double population;
};

// declaration & initialization
struct Anmial {
    char *name;
} doggo, catto, lambo;

union Country {
    char *name;
    double population;
} pak;

// function with struct as param
void printPersons(struct Person (*persons)[], int n) {
    for (size_t i = 0; i < n; ++i) {
        printf("--- Person Details ---\n");
        printf("Name: %s\n", (*persons)[i].name);
        printf("Age: %d\n", (*persons)[i].age);
        printf("Height: %.2f\n", (*persons)[i].height);
        printf("----------------------\n");
    }
}

int main(int argc, char const *argv[]) {
    // initialization
    struct Person bunnu = {"Bunnu", 21, 6.1};
    struct Person *bunnuPtr = &bunnu;

    // persons array
    // struct Person persons[] = {bunnu};
    struct Person persons[] = {bunnu};
    printPersons(&persons, sizeof(persons) / sizeof(persons[0]));

    // member operator (.)
    printf("%s\n", bunnu.name);
    // structure pointer operator (->)
    printf("%s\n", bunnuPtr->name);

    // accessing doggo, catto
    doggo.name = "Keyush";

    // union
    union Nation india;
    india.name = "India";
    // when india.population is assigned a value,
    // india.name will no longer hold "India"
    india.population = 135.26;
    // printf("Nation: %s", india.name); // error
    printf("Population: %f\n", india.population);

    pak.name = "Pakistan";
    printf("Country: %s\n", pak.name);
    return 0;
}
