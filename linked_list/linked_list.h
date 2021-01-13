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

void printNodeWithIndex(struct Node* nodePtr, size_t index) {
    printf("\n");
    printf("Position: %ld\n", index);
    printf("Data: %d\n", nodePtr->data);
    printf("Link: %p\n", nodePtr->link);
}

void printLinkedList(struct Node* headerNode) {
    size_t index = 0;

    while (headerNode->link != NULL) {
        // header node have no data to print
        headerNode = headerNode->link;
        // print node data
        printf("%d ", headerNode->data);
    }
    printf("\n");
}

void printLinkedListDetailed(struct Node* headerNode) {
    size_t index = 0;

    while (headerNode->link != NULL) {
        // header node have no data to print
        headerNode = headerNode->link;
        // print node data
        printNodeWithIndex(headerNode, ++index);
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
    // traverse for the list end
    while (headerNode->link != NULL) {
        // header node have no data to print
        headerNode = headerNode->link;
    }

    // 3. update last node's link to point to new node
    headerNode->link = newNode;
}

void addNodeAtTheBeginning(struct Node* headerNode, int data) {
    /**
     * Logic
     *
     * 1. create a new node with asked data, link = temp var
     * 2. fix header node to point to new node's address
     *
     */

    // 1. create a new node with asked data, link = temp var
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // update new node's data
    newNode->data = data;
    // fix new nodes link
    newNode->link = headerNode->link;  // end node link

    // 2. fix header node to point to new node's address
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
    // traverse for the (n-1)th node
    for (size_t i = 0; i < n - 1; ++i) {
        headerNode = headerNode->link;
    }
    // update new node's link to (n-1)th node's link (nth node's address)
    newNode->link = headerNode->link;

    // 3. fix nth node's link to point to new node's address
    headerNode->link = newNode;
}