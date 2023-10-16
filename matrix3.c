#include <stdio.h>

int main() 
{
    int rows, cols;

    printf("Enter the number of rows in the matrix: ");
    scanf("%d", &rows);

    printf("Enter the number of columns in the matrix: ");
    scanf("%d", &cols);

    
    int matrix[rows][cols];

    printf("Enter the elements of the matrix:\n");

   
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    int count = 0; 

    printf("Non-zero elements and their indices:\n");
    
    // Iterate through the matrix to find and print non-zero elements and their indices
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                printf("Element: %d, Index (Row, Col): (%d, %d)\n", matrix[i][j], i, j);
                count++;
            }
        }
    }

    printf("Total non-zero elements: %d\n", count);

    return 0;
}

