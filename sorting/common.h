/*
Author: chankruze (chankruze@geekofia.in)
Created: Sat Jan 16 2021 12:53:10 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include <stdio.h>

void print_arr(int* arr, size_t length) {
    for (size_t i = 0; i < length;) {
        printf("%d", arr[i]);
        if (++i == length)
            printf("\n");
        else
            printf(" ");
    }
}