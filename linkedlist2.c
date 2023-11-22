#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node* next;
};

//to create a new node
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
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// insert a new node after a specific node data value
void insertAfterNode(struct Node* head, int searchData, int newData) 
{
    struct Node* currentNode = head;
    while (currentNode != NULL) 
    {
        if (currentNode->data == searchData) 
        {
            struct Node* newNode = createNode(newData);
            if (newNode) 
            {
                newNode->next = currentNode->next;
                currentNode->next = newNode;
                return;
            }
        }
        currentNode = currentNode->next;
    }
    printf("Node with data %d not found in the list.\n", searchData);
}


int main() 
{
    struct Node* head = NULL;
    int n, data, searchData, newData;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (int i = 0; i < n; ++i)
     {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Linked List created: ");
    displayList(head);

    printf("Enter the data value of the node to insert after: ");
    scanf("%d", &searchData);

    printf("Enter the data value for the new node: ");
    scanf("%d", &newData);

    insertAfterNode(head, searchData, newData);

    printf("Linked List after insertion: ");
    displayList(head);

    return 0;
}

