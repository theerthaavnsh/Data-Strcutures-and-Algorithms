#include <stdio.h>
#include <stdlib.h>

// function to calculate the mean of an array
double calculateMean(int arr[], int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum / size;
}

// Function to calculate the median of an array 
double calculateMedian(int arr[], int size) {
    // Sort the array in ascending order
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // If the size of the array is odd, return the middle element
    if (size % 2 != 0) {
        return arr[size / 2];
    }
    // If the size of the array is even, return the average of the two middle elements
    else {
        int middle1 = arr[(size - 1) / 2];
        int middle2 = arr[size / 2];
        return (double)(middle1 + middle2) / 2.0;
    }
}

// Function to calculate the mode of an array
int calculateMode(int arr[], int size) {
    int mode = arr[0];
    int maxCount = 1;
    int current = arr[0];
    int currentCount = 1;

    for (int i = 1; i < size; i++) {
        if (arr[i] == current) {
            currentCount++;
        } else {
            if (currentCount > maxCount) {
                maxCount = currentCount;
                mode = current;
            }
            current = arr[i];
            currentCount = 1;
        }
    }

    // Check if the mode is the last element
    if (currentCount > maxCount) {
        mode = current;
    }

    return mode;
}

int main() {
    int size;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    double mean = calculateMean(arr, size);
    double median = calculateMedian(arr, size);
    int mode = calculateMode(arr, size);

    printf("Mean: %.2lf\n", mean);
    printf("Median: %.2lf\n", median);
    printf("Mode: %d\n", mode);

    return 0;
}

