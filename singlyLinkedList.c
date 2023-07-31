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

    // DEBUG
    // Print to show data being added. 
    // printf("%d\n", newNode->data);
    }

void printNodes(struct Node* cursor) {
    while(cursor != NULL) {
        printf("%d", cursor->data);
        cursor = cursor->nextNode;
        if (cursor != NULL) {
            printf(" -> ");
        }
    }
};

int main() {
    // TODO: CHANGE TO IF NULL IN INSERT MAYBE?
    struct Node* head = NULL;

    // Line Break 
    printf("|----Testing----|\n");

    // Testing insertNode
    insertNode(&head, 0);
    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);

        // Print the List of Nodes
    printNodes(head);

    // Return needed
    return 0;
}