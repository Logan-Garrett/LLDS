#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct Node {
	char *name;
	int id;
	struct Node *nextNode;
};

struct List {
	struct Node *head;
	struct Node *tail;
};

struct Node *createNode(char *name, int id) {
	struct Node *newNode = malloc(sizeof(struct Node));
	if (newNode == NULL) {
		fprintf(stderr, "%s: Couldn't create memory for the Node; %s\n", "linkedlist", strerror(errno));
		exit(-1);
	}

	newNode->name = strdup(name);
	newNode->id = id;
	newNode->nextNode = NULL;

	return newNode;
} 

struct List *createList() {
	struct List *list = malloc(sizeof(struct List));

	if (list == NULL) {
		fprintf(stderr, "%s: Couldn't create memory for the List; %s\n", "linkedlist", strerror(errno));
		exit(-1);
	} 
	
	list->head = NULL;
	list->tail = NULL;
	
	return list;
}

void insertNode(struct Node *node, struct List *list) {
	if (list->head == NULL && list->tail == NULL) {
		list->head = node;
		list->tail = node;
	} else {	
		list->tail->nextNode = node;
		list->tail = node; 
	}
}

void printList(struct List *list) {
	struct Node *ptr = list->head;

	while (ptr != NULL) {
		if (ptr != list->head) {
			printf(" -> ");
		}
		printf("(%s, %d)", ptr->name, ptr->id);
		ptr = ptr->nextNode;
	}
	printf("\n");
}

void destroyList(struct List *list) {
	struct Node *ptr = list->head;
	struct Node *temp = NULL;

	while(ptr != NULL) {
		free(ptr->name);
		temp = ptr;
		ptr = ptr->nextNode;
		free(temp);
	}

	free(list);
}

int main() {
	struct List *list = createList();
	struct Node *tmp = NULL;
	
	tmp = createNode("Logan", 37);
	insertNode(tmp, list);
	
	tmp = createNode("Sam", 39);
	insertNode(tmp, list);
	
	tmp = createNode("Daniel", 47);
	insertNode(tmp, list);

	printList(list);

	destroyList(list);
	
	return 0;
}
