/*
Author: chankruze (chankruze@geekofia.in)
Created: Tue Jan 05 2021 19:02:43 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#define clear() printf("\e[1;1H\e[2J")
#define array_size(x) (sizeof(x) / sizeof((x)[0]))
#define print_arr(arr, len)            \
    printf("[");                       \
    for (size_t i = 0; i < len; ++i) { \
        if (len - 1 == i) {            \
            printf("%d", arr[i]);      \
        } else {                       \
            printf("%d, ", arr[i]);    \
        }                              \
    }                                  \
    printf("]\n")

#define print_2d_arr(arr, rowsCount, columnsCount)  \
    printf("\n\n[\n");                                  \
    for (size_t i = 0; i < rowsCount; ++i) {        \
        printf(" ");                     \
        for (size_t j = 0; j < columnsCount; ++j) { \
            if (columnsCount - 1 == j)              \
                printf("%d", arr[i][j]);            \
            else                                    \
                printf("%d, ", arr[i][j]);          \
        }                                           \
        printf("\n");       \
    }                                               \
    printf("]\n\n")
