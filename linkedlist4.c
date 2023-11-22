#include <stdio.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to add a new node at the end of the linked list
void append(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// Function to display the linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to insert a new node at a given position
void insertAtPosition(struct Node** headRef, int position, int newData) {
    struct Node* newNode = createNode(newData);
    if (newNode == NULL) {
        printf("Memory allocation failed for the new node.\n");
        return;
    }

    if (position == 1 || *headRef == NULL) {
        newNode->next = *headRef;
        *headRef = newNode;
        return;
    }

    struct Node* current = *headRef;
    int count = 1;
    while (count < position - 1 && current->next != NULL) {
        current = current->next;
        count++;
    }

    if (coun

