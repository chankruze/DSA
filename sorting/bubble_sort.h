/*
Author: chankruze (chankruze@geekofia.in)
Created: Tue Jan 26 2021 01:23:48 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include "common.h"

void bubble_sort(int* arr, size_t length, int verbose) {
    for (size_t pass = 0; pass < (length - 1); ++pass) {
        // to check if any elem is not bubbled (i.e. array is sorted)
        int flag = 0;
        if (verbose) printf("\npass = %ld\n", pass);

        // loop until 2nd last elem
        for (size_t i = 0; i < (length - pass - 1); ++i) {
            if (verbose)
                printf("arr[%ld] = %d, arr[%ld] = %d, arr[%ld] = %d\n", i - 1,
                       arr[i - 1], i, arr[i], i + 1, arr[i + 1]);

            if (arr[i] > arr[i + 1]) {
                // swap i min with i+1
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                ++flag;
            }
        }

        if (flag == 0) {
            if (verbose) printf("Array is sorted!\n");
            return;
        }
    }
}