/*
Author: chankruze (chankruze@geekofia.in)
Created: Tue Jan 05 2021 19:01:55 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include <stdio.h>

#include "../libs/chankruze.h"

int main(int argc, char const *argv[]) {
    int rows, columns;
    printf("Enter rows count: ");
    scanf("%d", &rows);
    printf("Enter columns count: ");
    scanf("%d", &columns);
    // init 2d array of size rows x columns
    int arr2d[rows][columns];

    printf("\n[*] Initialized 2D array [%dx%d]", rows, columns);
    print_2d_arr(arr2d, rows, columns);

    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            printf("Enter a value for ROW = %ld, COLUMN = %ld => ", i + 1,
                   j + 1);
            scanf("%d", &arr2d[i][j]);
        }
    }

    printf("\n[*] Updated 2D array");
    print_2d_arr(arr2d, rows, columns);

    return 0;
}
