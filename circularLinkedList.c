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
        if (cursor == *head) {
            break;
        }
    }

    return count;    
}

void insertNodeAtFront(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* cursor = *head;

    newNode->data = data;
    newNode->nextNode = *head;

    int length = lengthOfNodeList(&cursor);

    if (*head != NULL) {
        while (cursor->nextNode != *head &&  cursor->nextNode != NULL) {
            cursor = cursor->nextNode;
        }
        cursor->nextNode = newNode;
    }
    
    *head = newNode;
}

void deleteNodelist(struct Node** cursor) {
    struct Node* temp = *cursor;
    struct Node* nextNode;

    while (temp != NULL) {
        if (temp->nextNode == *cursor) {
            temp->nextNode = NULL;
        }
        nextNode = temp->nextNode;
        free(temp);
        temp=nextNode;
    }

    *cursor = NULL;

    printf("Cleared Node List.\n");
}

void printNodeList(struct Node** cursor) {
    struct Node* tempCursor = *cursor;

    int listLength = lengthOfNodeList(&tempCursor);

    int length = 0;

    while (tempCursor != NULL && listLength >= length) {
        printf("%d", tempCursor->data);
        tempCursor = tempCursor->nextNode;
        length++;
        if (tempCursor != NULL && listLength >= length) {
            printf(" -> ");
        }
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Insert At The Front of Circular Linked List.
    insertNodeAtFront(&head, 1);
    insertNodeAtFront(&head, 2);
    insertNodeAtFront(&head, 3);
    insertNodeAtFront(&head, 5);
    insertNodeAtFront(&head, 4);
    insertNodeAtFront(&head, 9);

    // Print count
    printf("Length of the list: %d\n", lengthOfNodeList(&head));

    // Print Node List
    printNodeList(&head);

    // Clear Node List
    deleteNodelist(&head);

    // Print Count after delete.
    printf("Length of the list: %d\n", lengthOfNodeList(&head));
    
    return 0;
}