#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

int nodeListLength(struct Node** cursor) {
    struct Node* tempCursor = *cursor;
    int count = 0;
    
    while (tempCursor != NULL) {
        count++;
        tempCursor = tempCursor->nextNode;
    }
    return count;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data=data;
    newNode->nextNode=*head;

    int length = nodeListLength(&temp);

    if (length > 0) {
        temp->prevNode = newNode;
    }

    *head = newNode;
}

void printNodeList(struct Node** cursor) {
    struct Node* tempCursor = *cursor;

    while (tempCursor != NULL) {
        printf("\n------Node Info------");
        if (tempCursor->prevNode != NULL) {
            printf("\nPrev Node: %d", tempCursor->prevNode->data);
        }
        printf("\nNode Data: %d", tempCursor->data);
        if (tempCursor->nextNode != NULL) {
            printf("\nNext Node: %d", tempCursor->nextNode->data);
        }
        tempCursor = tempCursor->nextNode;
    }
}

int main() {
    struct Node* head = NULL;
    
    insertNode(&head, 0);
    insertNode(&head, 1);
    insertNode(&head, 2);

    printf("\nThe Node List Length is: %d", nodeListLength(&head));

    printNodeList(&head);

    return 0;
}