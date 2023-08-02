#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

void insertNode(struct Node** head, int data) {
    printf("Inserted Node");
}

int main() {
    struct Node* head = NULL;
    
    insertNode(&head, 3);

    return 0;
}