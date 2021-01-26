/*
Author: chankruze (chankruze@geekofia.in)
Created: Tue Jan 26 2021 21:31:57 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include "common.h"

void insertion_sort(int* arr, size_t arr_len) {
    for (size_t i = 0; i < arr_len; ++i) {
        int val = arr[i];
        int hole = i;

        while (hole > 0 && arr[hole - 1] > val) {
            arr[hole] = arr[hole - 1];
            --hole;
        }

        arr[hole] = val;
    }
}