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
            cursor->nextNode = *head;
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

}

int main() {
    struct Node* head = NULL;

    insertNodeAtFront(&head, 0);

    printf("\nNode List length is: %d", nodeListLength(&head));

    return 0;
}