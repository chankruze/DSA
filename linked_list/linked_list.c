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
    printLinkedListDetailed(headerNode);

    // delete a node from the beginning
    deleteNodeAtTheBeginning(headerNode);
    printLinkedList(headerNode);

    // delete a node form the end
    deleteNodeAtTheEnd(headerNode);
    printLinkedList(headerNode);

    // delete a node from nth position
    deleteNodeAtNthPosition(headerNode, 4);
    printLinkedList(headerNode);
    deleteNodeAtNthPosition(headerNode, 1);
    printLinkedList(headerNode);
    deleteNodeAtNthPosition(headerNode, 1);
    printLinkedList(headerNode);
    deleteNodeAtNthPosition(headerNode, 1);
    printLinkedList(headerNode);
    deleteNodeAtNthPosition(headerNode, 1);
    printLinkedList(headerNode);
    deleteNodeAtNthPosition(headerNode, 1);
    printLinkedList(headerNode);
    deleteNodeAtNthPosition(headerNode, 1);
    printLinkedList(headerNode);
    deleteNodeAtNthPosition(headerNode, 5);
    printLinkedList(headerNode);
    //  checking deleting methods when list is empty.
    deleteNodeAtNthPosition(headerNode, 16);
    deleteNodeAtNthPosition(headerNode, 1);
    deleteNodeAtNthPosition(headerNode, 5);
    deleteNodeAtNthPosition(headerNode, 99);
    deleteNodeAtTheBeginning(headerNode);
    deleteNodeAtTheBeginning(headerNode);
    deleteNodeAtTheBeginning(headerNode);
    deleteNodeAtTheBeginning(headerNode);
    deleteNodeAtTheEnd(headerNode);
    deleteNodeAtTheEnd(headerNode);
    deleteNodeAtTheEnd(headerNode);
    deleteNodeAtTheEnd(headerNode);

    // print linked list detailed
    printLinkedListDetailed(headerNode);
    return 0;
}
