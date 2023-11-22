#include <stdio.h>
#include <stdlib.h>

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

// Function to insert a new node before a specific node data value
void insertBeforeNode(struct Node** headRef, int searchData, int newData) {
    struct Node* currentNode = *headRef;
    struct Node* prevNode = NULL;
    while (currentNode != NULL && currentNode->data != searchData) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentNode == NULL) {
        printf("Node with data %d not found in the list.\n", searchData);
        return;
    }
    struct Node* newNode = createNode(newData);
    newNode->next = currentNode;
    if (prevNode == NULL) {
        *headRef = newNode;
    } else {
        prevNode->next = newNode;
    }
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data, searchData, newData;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Linked List created: ");
    displayList(head);

    printf("Enter the data value of the node to insert before: ");
    scanf("%d", &searchData);

    printf("Enter the data value for the new node: ");
    scanf("%d", &newData);

    insertBeforeNode(&head, searchData, newData);

    printf("Linked List after insertion: ");
    displayList(head);

    return 0;
}

