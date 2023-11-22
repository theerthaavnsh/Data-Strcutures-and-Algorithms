#include <stdio.h>
#include <stdlib.h>

// node 
struct Node
{
    int data;
    struct Node* next;
};

//create a new node
struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) 
    {
        newNode->data = data;
        newNode->next = NULL;
    }
    return newNode;
}

// add a new node at the end of the linked list
void append(struct Node** headRef, int data) 
{
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) 
    {
        *headRef = newNode;
        return;
    }
    struct Node* lastNode = *headRef;
    while (lastNode->next != NULL) 
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

// display the linked list
void displayList(struct Node* head) 
{
    while (head != NULL) 
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() 
{
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

    return 0;
}

