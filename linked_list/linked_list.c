/*
Author: chankruze (chankruze@geekofia.in)
Created: Wed Jan 13 2021 17:56:43 GMT+0530 (India Standard Time)

Copyright (c) Geekofia 2021 and beyond
*/

#include "linked_list.h"

int main(int argc, char const* argv[]) {
    // init head as NULL (empty linked list)
    struct Node* head = NULL;

    // insertion tests
    printLinkedList(head);
    // add 5 nodes to linked list's end
    for (int i = 0; i < 5; ++i) {
        addNodeAtTheEnd(&head, (i * 10) + 10);
        // printf("head = %p", head);
    }
    printLinkedList(head);
    // insert a node at the end
    addNodeAtTheEnd(&head, 100);
    printLinkedList(head);
    // insert a node at the beginning
    addNodeAtTheBeginning(&head, 1);
    printLinkedList(head);
    // insert a node at nth position
    addNodeAtNthPosition(&head, 1, 69);
    printLinkedList(head);
    // insert a node at nth position
    addNodeAtNthPosition(&head, 2, 70);
    printLinkedList(head);
    // insert a node at nth position
    addNodeAtNthPosition(&head, 1, 96);
    printLinkedList(head);
    // insert a node at nth position
    addNodeAtNthPosition(&head, countNodes(head), 69);
    printLinkedList(head);

    // deletion tests
    // delete a node from the beginning
    deleteNodeAtTheBeginning(&head);
    printLinkedList(head);
    // delete a node form the end
    deleteNodeAtTheEnd(&head);
    printLinkedList(head);
    // delete a node from nth position
    deleteNodeAtNthPosition(&head, 4);
    printLinkedList(head);
    deleteNodeAtNthPosition(&head, 1);
    printLinkedList(head);
    deleteNodeAtNthPosition(&head, 7);
    printLinkedList(head);
    // delete a node by it's value
    deleteNodeWithValue(&head, 50);
    printLinkedList(head);

    // reverse linked list
    printf("[ORIGINAL] ");
    printLinkedList(head);
    reverseLinkedList(&head);
    printf("[REVERSED] ");
    printLinkedList(head);
    reverseLinkedList(&head);
    printf("[REVERSED] ");
    printLinkedList(head);

    //  checking deleting methods when list is empty.
    deleteNodeAtNthPosition(&head, 16);
    deleteNodeWithValue(&head, 40);
    deleteNodeAtNthPosition(&head, 5);
    deleteNodeAtNthPosition(&head, 99);
    deleteNodeAtTheBeginning(&head);
    deleteNodeAtTheBeginning(&head);
    deleteNodeAtTheBeginning(&head);
    deleteNodeAtTheBeginning(&head);
    deleteNodeAtTheEnd(&head);
    deleteNodeAtTheEnd(&head);
    deleteNodeAtTheEnd(&head);
    deleteNodeAtTheEnd(&head);

    // print detailed list
    printLinkedListDetailed(head);
    return 0;
}
