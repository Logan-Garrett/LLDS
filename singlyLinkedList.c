#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void insertNode(struct Node **head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
}

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

    printf("Hello World!");
    return 0;
}