#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

int lengthOfNodeList(struct Node** head) {
    struct Node* cursor = *head;
    int count = 0;

    while (cursor != NULL) {
        count++;
        cursor=cursor->nextNode;
    }

    printf("\nThe Length of the Node List: ");
    printf("%d", count);
    return count;    
}

void insertNodeAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assign info to the Node Struct.
    newNode->data=data;
    newNode->nextNode=*head;

    if (newNode->nextNode == NULL) {
        printf("I am NULL");
        newNode->nextNode = *head; // Issue here assigning it to start instead of endNode.
    }

    *head = newNode;
}

void printNodeList(struct Node** cursor) {
    struct Node* tempCursor = *cursor;

    while (tempCursor != NULL) {
        printf("%d", tempCursor->data);
        tempCursor = tempCursor->nextNode;
        if (tempCursor != NULL) {
            printf(" -> ");
        }
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Insert At The Front of Circular Linked List.
    insertNodeAtFront(&head, 0);
    insertNodeAtFront(&head, 1);
    insertNodeAtFront(&head, 3);

    lengthOfNodeList(&head);

    // Print Node List
    printNodeList(&head);

    return 0;
}