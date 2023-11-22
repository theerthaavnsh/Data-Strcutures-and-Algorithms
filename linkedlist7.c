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

// Function to delete the node containing the smallest element
void deleteSmallestElement(struct Node** headRef) {
    if (*headRef == NULL) {
        printf("List is empty, deletion is not possible.\n");
        return;
    }

    struct Node* temp = *headRef;
    struct Node* prev = NULL;
    struct Node* smallestNode = *headRef;
    int smallestValue = smallestNode->data;

    while (temp != NULL) {
        if (temp->data < smallestValue) {
            smallestValue = temp->data;
            smallestNode = temp;
        }
        temp = temp->next;
    }

    temp = *headRef;
    while (temp != smallestNode) {
        prev = temp;
        temp = temp->next;
    }

    if (prev == NULL) {
        *headRef = smallestNode->next;
    } else {
        prev->next = smallestNode->next;
    }

    free(smallestNode);
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Linked List created: ");
    displayList(head);

    deleteSmallestElement(&head);

    printf("Linked List after deleting the smallest element: ");
    displayList(head);

    return 0;
}

