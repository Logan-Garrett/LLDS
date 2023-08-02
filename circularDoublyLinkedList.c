#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

void insertNodeAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    struct Node* cursor = *head;

    newNode->data = data;
    newNode->nextNode = *head;

    newNode->prevNode = NULL;

    if (*head != NULL) {
        temp->prevNode = newNode;
    }

    while (cursor != NULL) {
        if (cursor->nextNode == *head) {
            // Data assingment Seems off in terms of making it Circular.
            cursor->nextNode = newNode;
            newNode->prevNode = cursor->nextNode;
        }
        cursor = cursor->nextNode;
    }

    *head = newNode;
}  

int nodeListLength(struct Node** cursor) {
    struct Node* tempCursor = *cursor;
    int length = 0;

    while (tempCursor != NULL && tempCursor->nextNode != *cursor) {
        length++;
        tempCursor = tempCursor->nextNode;
    }

    return length;
}

void printNodeList(struct Node** cursor) {
    struct Node* tempCursor = *cursor;
    
    int listLength = nodeListLength(&tempCursor);
    int length = 0;

    while (tempCursor != NULL && listLength > length) {
        printf("\n------Node Info------");
        if (tempCursor->prevNode != NULL) {
            printf("\nPrev Node: %d", tempCursor->prevNode->data);
        }

        printf("\nNode Data: %d", tempCursor->data);

        if (tempCursor->nextNode != NULL) {
            printf("\nNext Node: %d", tempCursor->nextNode->data);
        }

        length++;
        tempCursor = tempCursor->nextNode;
    }    
}

int main() {
    struct Node* head = NULL;

    insertNodeAtFront(&head, 0);
    insertNodeAtFront(&head, 3);
    insertNodeAtFront(&head, 2);
    insertNodeAtFront(&head, 6);
    insertNodeAtFront(&head, 9);

    printf("\nNode List length is: %d", nodeListLength(&head));

    printNodeList(&head);

    return 0;
}