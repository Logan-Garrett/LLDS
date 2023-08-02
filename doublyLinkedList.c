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
    printf("\nInserted Node");
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data=data;
    newNode->nextNode=*head;

    int length = nodeListLength(&temp);
    printf("\nLength From insert: %d", length);

    if (length > 0) {
        temp->prevNode = newNode;
        printf("\nPreviouse Node %d", temp->prevNode->data);
    }

    *head = newNode;
}

void printNodeList(struct Node** cursor) {
    // Not Implemented.
}

int main() {
    struct Node* head = NULL;
    
    insertNode(&head, 0);
    insertNode(&head, 1);
    insertNode(&head, 2);

    printf("\nThe Node List Length is: %d", nodeListLength(&head));

    return 0;
}