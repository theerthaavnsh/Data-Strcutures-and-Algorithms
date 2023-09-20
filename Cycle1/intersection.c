#include <stdio.h>

// function to find the intersection of two sets
void findIntersection(int arr1[], int size1, int arr2[], int size2) {
    printf("Intersection of S1 and S2: {");
    
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr1[i] == arr2[j]) {
                printf("%d", arr1[i]);
                if (i < size1 - 1) {
                    printf(", ");
                }
                break; // break out of the inner loop once a match is found
            }
        }
    }
    
    printf("}\n");
}

int main() {
    int size1, size2;

    printf("Enter the number of elements in S1: ");
    scanf("%d", &size1);

    int S1[size1];

    printf("Enter the elements of S1:\n");
    for (int i = 0; i < size1; i++) {
        scanf("%d", &S1[i]);
    }

    printf("Enter the number of elements in S2: ");
    scanf("%d", &size2);

    int S2[size2];

    printf("Enter the elements of S2:\n");
    for (int i = 0; i < size2; i++) {
        scanf("%d", &S2[i]);
    }

    findIntersection(S1, size1, S2, size2);

    return 0;
}

