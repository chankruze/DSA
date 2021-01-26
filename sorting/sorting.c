/*
Author: chankruze (chankruze@geekofia.in)
Created: Sat Jan 16 2021 03:10:35 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include "bubble_sort.h"
#include "selection_sort.h"
#include "insertion_sort.h"

int main(int argc, char const* argv[]) {
    // arrays
    int arr1[] = {3, 7, 8, 1, 0, 4, 2};
    int arr2[] = {1, 2, 3, 4, 5, 6, 7};
    int arr3[] = {4, 2, 3, 6, 8, 69, 5};
    int arr4[] = {4, 0, 8, 6, 7, 69, 1};
    size_t arr1_len = (&arr1)[1] - arr1;
    size_t arr2_len = (&arr2)[1] - arr2;
    size_t arr3_len = (&arr3)[1] - arr3;
    size_t arr4_len = (&arr4)[1] - arr4;

    // selection sort
    printf("---- SELECTION SORT ----\n");
    printf("[ORIGINAL] ");
    print_arr(arr1, arr1_len);
    selection_sort(arr1, arr1_len);
    printf("[SORTED]   ");
    print_arr(arr1, arr1_len);

    // bubble sort
    printf("\n---- BUBBLE SORT ----\n");
    printf("[ORIGINAL] ");
    print_arr(arr3, arr3_len);
    bubble_sort(arr3, arr3_len, 1);
    printf("\n[SORTED]   ");
    print_arr(arr3, arr3_len);

    printf("\n[ORIGINAL] ");
    print_arr(arr2, arr2_len);
    bubble_sort(arr2, arr2_len, 0);
    printf("[SORTED]   ");
    print_arr(arr2, arr2_len);

    // selection sort
    printf("---- INSERTION SORT ----\n");
    printf("[ORIGINAL] ");
    print_arr(arr4, arr4_len);
    insertion_sort(arr4, arr4_len);
    printf("[SORTED]   ");
    print_arr(arr4, arr4_len);

    return 0;
}
