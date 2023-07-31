#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void insertNode(struct Node** head, int nodeData) {
    // Allocate Memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Give the Node data and point to the previous head as next
    // Meaning this inserts on the front.
    newNode->data = nodeData;
    newNode->nextNode = *head;

    // Sets this Node as the new Head Node at the front.
    *head = newNode;

    // Print to show data being added.
    printf("%d\n", newNode->data);
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

    // Line Break 
    printf("|----Testing Manuel Insert----|\n");

    // Print the List of Nodes
    printNodes(head);

    // Line Break 
    printf("|----Testing Insert Function----|\n");

    // Testing insertNode
    insertNode(&head, 0);

    // Test to make sure everything is running
    // printf("Hello World!");
    // Return needed
    return 0;
}