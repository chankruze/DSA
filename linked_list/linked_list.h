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

int isEmptyList(struct Node* head) { return head == NULL; }

void printNodeWithIndex(struct Node* nodePtr, size_t index) {
    printf("\n");
    printf("Position: %ld\n", index);
    printf("Data: %d\n", nodePtr->data);
    nodePtr->link == NULL ? printf("Link: NULL\n")
                          : printf("Link: %p\n", nodePtr->link);
}

void printLinkedList(struct Node* head) {
    printf("[LIST]");
    if (isEmptyList(head)) {
        printf(" List is empty.\n");
        return;
    }

    while (head != NULL) {
        // print node data
        printf(" %d", head->data);
        head = head->link;
    }
    printf("\n");
}

void printLinkedListDetailed(struct Node* head) {
    size_t index = 0;

    printf("\n------------------------\n");
    printf("| Detailed Linked List |\n");
    printf("------------------------");
    if (head == NULL) {
        printf("\nList is empty.\n");
        printf("------------------------\n");
        return;
    }

    while (head != NULL) {
        // print node data
        printNodeWithIndex(head, ++index);
        head = head->link;
    }
    printf("------------------------\n\n");
}

size_t countNodes(struct Node* head) {
    if (isEmptyList(head)) return 0;

    size_t nodes = 0;
    while (head != NULL) {
        head = head->link;
        ++nodes;
    }
    return nodes;
}

void addNodeAtTheEnd(struct Node** head, int data) {
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

    // if empty list
    if (isEmptyList(*head)) {
        *head = newNode;
        return;
    }

    // 2. traverse entire list to find the last node
    // traverse for the list end
    struct Node* temp = *head;
    while (temp->link != NULL) {
        // header node have no data to print
        temp = temp->link;
    }

    // 3. update last node's link to point to new node
    temp->link = newNode;
}

void addNodeAtTheBeginning(struct Node** head, int data) {
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
    // fix new nodes link to point to current head's link
    if (isEmptyList(*head))
        newNode->link = NULL;
    else
        newNode->link = *head;

    // 2. fix header node to point to new node's address
    *head = newNode;
}

void addNodeAtNthPosition(struct Node** head, size_t n, int data) {
    /**
     * Logic
     *
     * 1. create a new node with asked data
     * 2. traverse the list to (n-1)th node, update new node's link to (n-1)th
     * node's link
     * 3. fix nth node's link to point to new node's address
     *
     */

    // is empty list -> return
    if (isEmptyList(*head)) {
        printf("[ERROR] List is empty. Can't add %d at %ldth position\n", data,
               n);
        return;
    }

    // cheack if provided n is a valid position
    size_t totalNodes = countNodes(*head);

    if (n > totalNodes) {
        printf(
            "[ERROR] Total %ld nodes present. %ldth node can't be created.\n",
            totalNodes, n);
        return;
    }

    // 1. create a new node dynamically  asked data
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    // update new node's data
    newNode->data = data;

    if (n == 1) {
        newNode->link = *head;
        *head = newNode;
        return;
    }

    // 2. traverse the list to (n-1)th node, update new node's link to (n-1)th
    // node's link
    // traverse for the (n-1)th node
    struct Node* temp = *head;
    for (size_t i = 1; i < n - 1; ++i) {
        temp = temp->link;
    }
    // update new node's link to (n-1)th node's link (nth node's address)
    newNode->link = temp->link;

    // 3. fix nth node's link to point to new node's address
    temp->link = newNode;
}

void deleteNodeAtTheBeginning(struct Node** head) {
    /**
     * Logic
     *
     * 1. store 1st node's adress in temp node
     * 2. update header node's link to the temp node's link
     * 3. free (deallocate) memory of deleted node
     *
     */

    // is empty list -> return
    if (isEmptyList(*head)) {
        printf("[ERROR] List is empty. Can't delete the first node\n");
        return;
    }

    // 1. store 1st node's adress in temp node
    struct Node* temp = *head;

    // 2. update header node's link to the temp node's link
    *head = temp->link;

    // 3. free (deallocate) memory of deleted node
    printf("[INFO] Deleted %d from the beginning\n", temp->data);
    free(temp);
}

void deleteNodeAtTheEnd(struct Node** head) {
    /**
     * Logic
     *
     * 1. traverse the list to the end while keeping track of previous node
     * 2. update 2nd last node's link to NULL
     * 3. free (deallocate) memory of deleted node
     *
     */

    // is empty list -> return
    if (isEmptyList(*head)) {
        printf("[ERROR] List is empty. Can't delete the last node\n");
        return;
    }

    // 1. traverse the list to the end while keeping track of previous node
    struct Node* prevNode = *head;
    struct Node* temp = *head;

    while (temp->link != NULL) {
        // keep track of previous node
        prevNode = temp;
        // update current node to next node
        temp = temp->link;
    }

    // 2. update 2nd last node's link to NULL
    prevNode->link = NULL;

    // 3. free (deallocate) memory of deleted node
    printf("[INFO] Deleted %d from the end\n", temp->data);
    free(temp);
}

void deleteNodeAtNthPosition(struct Node** head, size_t n) {
    /**
     * Logic
     *
     * 1. traverse the list to the nth node while keeping track of previous node
     * 2. update (n-1)th node's link to nth's link
     * 3. free (deallocate) memory of deleted node
     *
     */

    // is empty list -> return
    if (isEmptyList(*head)) {
        printf("[ERROR] List is empty. Can't delete %ldth position\n", n);
        return;
    }

    // check if nth element is presen
    size_t totalNodes = countNodes(*head);

    if (n > totalNodes) {
        printf("[ERROR] Total %ld nodes present. %ldth node not present.\n",
               totalNodes, n);
        return;
    }

    // 1. traverse the list to the end while keeping track of previous node
    struct Node* prevNode = *head;
    struct Node* temp = *head;

    if (n == 1) {
        *head = prevNode->link;
        printf("[INFO] Deleted %d from %ldth position\n", temp->data, n);
        free(prevNode);
        return;
    }

    for (size_t i = 1; i < n; ++i) {
        // keep track of previous node
        prevNode = temp;
        // update current node to next node
        temp = temp->link;
    }

    // 2. update (n-1)th node's link to nth's link
    prevNode->link = temp->link;

    // 3. free (deallocate) memory of deleted node
    printf("[INFO] Deleted %d from %ldth position\n", temp->data, n);
    free(temp);
}

void deleteNodeWithValue(struct Node** head, int value) {
    /**
     * Logic
     *
     * 1. traverse the list to find the value's position
     * 2. delete the node at that position
     * 3. free (deallocate) memory of deleted node
     *
     */

    // is empty list -> return
    if (isEmptyList(*head)) {
        printf("[ERROR] List is empty. Can't delete node with value %d\n",
               value);
        return;
    }

    // check if element with given value is present
    struct Node* temp = *head;
    size_t index = 0;
    int isValueFound = 0;

    while (temp != NULL && !isValueFound) {
        isValueFound = (temp->data == value);
        temp = temp->link;
        ++index;
    }

    deleteNodeAtNthPosition(head, index);
}

void reverseLinkedList(struct Node** head) {
    /**
     * Logic
     *
     * 1. traverse the list to the while keeping track of previous node
     * 2. point the link of each node to it's previous node
     *
     */

    if (isEmptyList(*head)) return;

    struct Node *prevNode = NULL, *nextNode, *current = *head;

    while (current != NULL) {
        // save next node's address to nextNode
        nextNode = current->link;
        // printf("\ndata -> %d\n", current->data);
        // printf("next -> %p\n", nextNode);
        // break original link & point current node to it's previous node
        current->link = prevNode;
        // save current node's address to previous node (to use in next iter)
        prevNode = current;
        // printf("prev -> %p\n", prevNode);
        // save next node's address to current node (for next iter)
        current = nextNode;
        // printf("curr -> %p\n\n", current);
    }

    *head = prevNode;
}
