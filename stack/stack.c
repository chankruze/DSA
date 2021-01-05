/*
Author: chankruze (chankruze@geekofia.in)
Created: Tue Jan 05 2021 19:48:31 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include <stdio.h>

#include "../libs/chankruze.h"

#define EMPTY_TOP -1

// empty fn
int isEmpty(int *top) { return *top == EMPTY_TOP; }

// full fn
int isFull(int *top, int *max_size) { return *top == *max_size - 1; }

// peek fn
int peek(int (*stack)[], int *top) { return (*stack)[*top]; }

// push (insertion)
int push(int (*stack)[], int *top, int *max_size, int value) {
    if (!isFull(top, max_size)) {
        (*stack)[++*top] = value;
        printf("[I] pushed %d\n", value);
    } else {
        printf("[E] stack is full: could not insert data.\n");
    }
}

// pop (deletion)
int pop(int (*stack)[], int *top) {
    if (!isEmpty(top)) {
        int value = (*stack)[*top];
        *top = *top - 1;
        printf("[I] poped %d\n", value);
    } else {
        printf("[E] stack is empty: could not retrive data.\n");
    }
}

int main(int argc, char const *argv[]) {
    int max_size, top = EMPTY_TOP;
    printf("\n\tWelcome to STACK!\n\n");
    printf("Enter the max size of the stack: ");
    scanf("%d", &max_size);

    // initialize stack
    int stack[max_size];
    // // replace garbage value with 0 (for prettify printing)
    // for (int i = 0; i < max_size; i++) {
    //     push(&stack, &top, &max_size, 0);
    // }
    // top = EMPTY_TOP;  // reset top
    printf("\n[I] initialized stack of size %d\n", max_size);

    int choice = 0;
    // main loop
    while (1) {
        printf("\nFollowing operations are supported:\n\n");
        printf("\t1. push\n");
        printf("\t2. pop\n");
        printf("\t3. check if stack is empty\n");
        printf("\t4. check if stack is full\n");
        printf("\t5. peek top element\n");
        printf("\t0. quit\n");
        printf("\nMake your selection [1/2/3/4/5/0]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                return 0;
            case 1:
                // --- PUSH --- //
                printf("\nHow many items to push ?: ");
                int pushCount = 0, val = 0;
                scanf("%d", &pushCount);
                for (int i = 0; i < pushCount; ++i) {
                    printf("[%d/%d] Enter value to push: ", i + 1, pushCount);
                    scanf("%d", &val);
                    push(&stack, &top, &max_size, val);
                    // if (isFull(&top, &max_size)) break;
                }

                printf("\n[I] Current Top = %d\n", top);
                printf("[I] Element currently at top of the stack: %d\n",
                       peek(&stack, &top));
                break;
            case 2:
                // --- POP --- //
                printf("\nHow many items to pop ?: ");
                int popCount = 0;
                scanf("%d", &popCount);
                for (int i = 0; i < popCount; ++i) {
                    pop(&stack, &top);
                    // if (isEmpty(&top)) break;
                }

                printf("\n[I] Current Top = %d\n", top);
                printf("[I] Element currently at top of the stack: %d\n",
                       peek(&stack, &top));
                break;
            case 3:
                printf("\n[I] Stack is ");
                isEmpty(&top) ? printf("Empty") : printf("Not Empty");
                printf("\n");
                break;
            case 4:
                printf("\n[I] Stack is ");
                isFull(&top, &max_size) ? printf("Full") : printf("Not Full");
                printf("\n");
                break;
            case 5:
                printf("\n[I] Current Top = %d\n", top);
                printf("[I] Element currently at top of the stack: %d\n",
                       peek(&stack, &top));
                break;
        }
    }

    return 0;
}
