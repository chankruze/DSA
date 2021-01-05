/*
Author: chankruze (chankruze@geekofia.in)
Created: Mon Oct 12 2020 14:51:41 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2020 and beyond
*/
#include <stdio.h>

#include "../libs/chankruze.h"

// main
int main(int argc, char const *argv[]) {
    // clear screen
    clear();
    int len = 5;
    printf("[INPUT] Enter the length for the array: ");
    scanf("%d", &len);
    // int array of n elements
    int arr[len];
    // int arr[len] = {}; // will raise `variable-sized object may not be
    // initialized` error length of an int array int len = array_size(arr);
    // print
    printf("[I] Length of Array = %d\n", len);

    /*
    => Traversing linear array
    */
    printf("\n[*] Traversing linear array\n\n");

    for (size_t i = 0; i < len; ++i) {
        printf("Index: %ld, Value: %d\n", i, arr[i]);
    }

    /*
    => Updating elements in linear array
    */
    printf("\n[*] Updating elements in linear array\n\n");

    for (size_t i = 0; i < len; ++i) {
        int old = arr[i];
        printf("[INPUT] Set new value for index %ld: ", i);
        scanf("%d", &arr[i]);
        printf("index: %ld\told_value: %d\tnew_value: %d\n\n", i, old, arr[i]);
    }

    print_arr(arr, len);

    /*
    => Inserting element in linear array
    */
    // insert at index (index = position - 1)
    printf("\n[*] Inserting an element in linear array\n\n");
    printf("[INPUT] Enter a value to insert: ");
    int new;
    scanf("%d", &new);
    printf("[INPUT] Enter a position to insert: ");
    int position;
    scanf("%d", &position);

    // shift elements forward
    for (size_t i = len; i >= position; i--) {
        arr[i] = arr[i - 1];
    }

    arr[position - 1] = new;
    print_arr(arr, array_size(arr) + 1);

    /*
    => Deleting element in linear array
    */
    // delete by index (index = position - 1)
    printf("\n[*] Deleting an element in linear array\n\n");
    printf("[INPUT] Enter the postion of the element to delete: ");
    int delPos;
    scanf("%d", &delPos);

    // shift elements backward
    for (size_t i = (delPos - 1); i < len; i++) {
        arr[i] = arr[i + 1];
    }
    print_arr(arr, array_size(arr));

    // delete by value
    return 0;
}
