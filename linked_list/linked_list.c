/*
Author: chankruze (chankruze@geekofia.in)
Created: Wed Jan 13 2021 17:56:43 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include "linked_list.h"

int main(int argc, char const* argv[]) {
    // initialize a linked list
    struct Node* headerNode = (struct Node*)malloc(sizeof(struct Node));
    // empty list
    headerNode->link = NULL;

    // add 5 nodes to linked list
    for (int i = 0; i < 5; ++i) {
        addNodeAtTheEnd(headerNode, (i * 10) + 10);
    }

    // add 5 nodes to linked list
    for (int i = 0; i < 5; ++i) {
        addNodeAtTheBeginning(headerNode, (i * 10) + 1);
    }

    // print linked list elements
    printLinkedList(headerNode);

    addNodeAtNthPosition(headerNode, 7, 69);

    // print linked list elements
    printLinkedList(headerNode);

    // print linked list detailed
    printLinkedListDetailed(headerNode);

    return 0;
}
