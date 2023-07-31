#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void insertNode(struct Node **head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
}

void printNodes(struct Node* cursor) {
    while(cursor != NULL) {
        printf("%d\n", cursor->data);
        cursor=cursor->nextNode;
    }
};

int main() {
    // Memory Allocation
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* one = (struct Node*)malloc(sizeof(struct Node));
    struct Node* two = (struct Node*)malloc(sizeof(struct Node));
    struct Node* three = (struct Node*)malloc(sizeof(struct Node));

    // Giving Nodes data
    head->data=0;
    one->data=1;
    two->data=2;
    three->data=3;

    // Pointing Nodes to next
    head->nextNode=one;
    one->nextNode=two;
    two->nextNode=three;

    // Print the List of Nodes
    printNodes(head);

    // Test to make sure everything is running
    printf("Hello World!");
    return 0;
}