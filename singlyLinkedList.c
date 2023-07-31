#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *nextNode;
};

void insertNodeAtFront(struct Node** head, int nodeData) {
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

void insertNodeAtEnd(struct Node** head, int nodeData) {
    // Allocate Memory
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // Assert New Node Data
    newNode->data = nodeData;
    
    // Store Head Location
    struct Node* temp = *head;

    // Asset New Node Next 
    newNode->nextNode = NULL;

    // Check if LL is empty and if so make newNode Head.
    if (*head == NULL) {
        *head == newNode;
        return;
    }

    // Go to Last Node
    while (temp->nextNode != NULL) {
        temp = temp->nextNode;
    }
    // Change temp to point to newNode
    temp->nextNode = newNode;

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
    printf("\n");
};

int main() {
    struct Node* head = NULL;

    // Line Break 
    printf("|----Testing----|\n");

    // Testing insertNodeAtFront
    insertNodeAtFront(&head, 0);
    insertNodeAtFront(&head, 1);
    insertNodeAtFront(&head, 2);
    insertNodeAtFront(&head, 3);

    // Print Insert at Front Nodes
    printNodes(head);

    // Testing insertNodeAtEnd
    insertNodeAtEnd(&head, 10);
    insertNodeAtEnd(&head, 11);
    insertNodeAtEnd(&head, 12);
    insertNodeAtEnd(&head, 13);

    // Print the List of Nodes
    printNodes(head);

    // Return
    return 0;
}