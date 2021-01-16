/*
Author: chankruze (chankruze@geekofia.in)
Created: Sat Jan 16 2021 02:56:39 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include "common.h"

void selection_sort(int* arr, size_t length) {
    // traverse the array till (len - 2)
    for (size_t i = 0; i < length - 2; ++i) {
        // assume minimum value is at i
        int min = i;

        // find min from index i + 1 and rest
        for (size_t j = i + 1; j < length; ++j) {
            if (arr[j] < arr[min]) {
                min = j;  // update index of next minimum
            }
        }

        // swap prev min with next min
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}