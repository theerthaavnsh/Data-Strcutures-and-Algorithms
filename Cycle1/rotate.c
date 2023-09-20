#include <stdio.h>

// function to rotate the array
void rotate(int a[], int n, char d, int cr) {
    if (d == 'l' || d == 'L') { // Rotate left
        cr = cr % n; // normalize the rotation count
        for (int i = 0; i < cr; i++) {
            int temp = a[0];
            for (int j = 0; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            a[n - 1] = temp;
        }
    } else if (d == 'r' || d == 'R') { // Rotate right
        cr = cr % n; // to normalize the rotation count
        for (int i = 0; i < cr; i++) {
            int temp = a[n - 1];
            for (int j = n - 1; j > 0; j--) {
                a[j] = a[j - 1];
            }
            a[0] = temp;
        }
    }
}

int main() {
    int n, cr;
    char d;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter direction of rotation (L for left, R for right): ");
    scanf(" %c", &d);

    printf("Enter the count of rotations: ");
    scanf("%d", &cr);

    rotate(a, n, d, cr);

    printf("Rotated Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

