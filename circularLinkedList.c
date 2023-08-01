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

    if (*head == NULL) {
        printf("I am NULL");
    }

    *head = newNode;
}

int main() {
    struct Node* head = NULL;
    
    // Insert At The Front of Circular Linked List.
    insertNodeAtFront(&head, 0);

    lengthOfNodeList(&head);

    return 0;
}