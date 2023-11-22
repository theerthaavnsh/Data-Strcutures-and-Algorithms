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

// Function to delete a node at a given position
void deleteAtPosition(struct Node** headRef, int position) {
    if (*headRef == NULL) {
        printf("List is empty, deletion is not possible.\n");
        return;
    }

    struct Node* temp = *headRef;
    if (position == 1) {
        *headRef = temp->next;
        free(temp);
        return;
    }

    int count = 1;
    struct Node* prev = NULL;
    while (temp != NULL && count != position) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Main function
int main() {
    struct Node* head = NULL;
    int n, data, position;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i) {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Linked List created: ");
    displayList(head);

    printf("Enter the position to delete a node: ");
    scanf("%d", &position);

    if (position <= 0) {
        printf("Invalid position for deletion.\n");
    } else {
        deleteAtPosition(&head, position);

        printf("Linked List after deletion: ");
        displayList(head);
    }

    return 0;
}

