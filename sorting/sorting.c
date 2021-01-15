/*
Author: chankruze (chankruze@geekofia.in)
Created: Sat Jan 16 2021 03:10:35 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include "selection_sort.h"

void print_arr(int* arr, size_t length) {
    for (size_t i = 0; i < length;) {
        printf("%d", arr[i]);
        if (++i == length)
            printf("\n");
        else
            printf(" ");
    }
}

int main(int argc, char const* argv[]) {
    // arrays
    int arr1[] = {3, 7, 8, 1, 0, 4, 2};
    size_t arr1_len = (&arr1)[1] - arr1;

    // selection sort
    printf("[ORIGINAL] ");
    print_arr(arr1, arr1_len);
    selection_sort(arr1, arr1_len);
    printf("[SORTED]   ");
    print_arr(arr1, arr1_len);

    return 0;
}
