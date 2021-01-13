/*
Author: chankruze (chankruze@geekofia.in)
Created: Wed Jan 13 2021 17:56:52 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
};

// void printNode(struct Node* nodePtr) {
//     printf("%d", nodePtr->data);
// }

void printNodeWithIndex(struct Node* nodePtr, size_t index) {
    printf("\n");
    printf("Position: %ld\n", index);
    printf("Data: %d\n", nodePtr->data);
    printf("Link: %p\n", nodePtr->link);
}

void printLinkedList(struct Node* headerNode) {
    struct Node* temp = headerNode;
    size_t index = 0;

    while (temp->link != NULL) {
        // header node have no data to print
        temp = temp->link;
        // print node data
        printf("%d ", temp->data);
    }
    printf("\n");
}

void printLinkedListDetailed(struct Node* headerNode) {
    struct Node* temp = headerNode;
    size_t index = 0;

    while (temp->link != NULL) {
        // header node have no data to print
        temp = temp->link;
        // print node data
        printNodeWithIndex(temp, ++index);
    }
}

void addNodeAtTheEnd(struct Node* headerNode, int data) {
    /**
     * Logic
     *
     * 1. create a new node with asked data
     * 2. traverse entire list to find the last node
     * 3. update last node's link to point to new node
     *
     */

    // 1. create a new node dynamically
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // update new node's data
    newNode->data = data;
    // fix new nodes link
    newNode->link = NULL;  // end node link

    // 2. traverse entire list to find the last node
    //  hold node temporarily to traverse the list
    struct Node* lastNode = headerNode;
    // traverse for the list end
    while (lastNode->link != NULL) {
        // header node have no data to print
        lastNode = lastNode->link;
    }

    // 3. update last node's link to point to new node
    lastNode->link = newNode;
}

void addNodeAtTheBeginning(struct Node* headerNode, int data) {
    /**
     * Logic
     *
     * 1. store header node's link (1st node) to a temp variable
     * 2. create a new node with asked data, link = temp var
     * 3. fix header node to point to new node's address
     *
     */

    // 1. store header node's link (1st node) to a temp variable
    struct Node* temp = headerNode;

    // 2. create a new node with asked data, link = temp var
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // update new node's data
    newNode->data = data;
    // fix new nodes link
    newNode->link = headerNode->link;  // end node link

    // 3. fix header node to point to new node's address
    headerNode->link = newNode;
}

void addNodeAtNthPosition(struct Node* headerNode, size_t n, int data) {
    /**
     * Logic
     *
     * 1. create a new node with asked data
     * 2. traverse the list to (n-1)th node, update new node's link to (n-1)th
     * node's link
     * 3. fix nth node's link to point to new node's address
     *
     */

    // 1. create a new node dynamically  asked data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // update new node's data
    newNode->data = data;

    // 2. traverse the list to (n-1)th node, update new node's link to (n-1)th
    // node's link
    // hold node temporarily to traverse the list upto (n-1)th node
    struct Node* nMinus1thNode = headerNode;
    // traverse for the (n-1)th node
    for (size_t i = 0; i < n - 1; ++i) {
        nMinus1thNode = nMinus1thNode->link;
    }
    // update new node's link to (n-1)th node's link (nth node's address)
    newNode->link = nMinus1thNode->link;

    // 3. fix nth node's link to point to new node's address
    nMinus1thNode->link = newNode;
}