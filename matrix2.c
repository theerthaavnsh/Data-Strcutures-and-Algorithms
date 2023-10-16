#include <stdio.h>

//calculate and print the sum of elements in each row
void rowsum(int matrix[][10], int rows, int cols) 
{
    for (int i = 0; i < rows; i++)
     {
        int sum = 0;
        for (int j = 0; j < cols; j++)
         {
            sum += matrix[i][j];
        }
        printf("Sum of elements in row %d: %d\n", i + 1, sum);
    }
}

//calculate and print the sum of elements in each column
void colsum(int matrix[][10], int rows, int cols) 
{
    for (int j = 0; j < cols; j++) 
    {
        int sum = 0;
        for (int i = 0; i < rows; i++) 
        {
            sum += matrix[i][j];
        }
        printf("Sum of elements in column %d: %d\n", j + 1, sum);
    }
}

int main() 
{
    int rows, cols;

    printf("Enter the number of rows and columns of the matrix (up to 10): ");
    scanf("%d %d", &rows, &cols);

    int matrix[10][10];

    printf("Enter the elements of the matrix:\n");

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Calculate and print row and column sums
    rowsum(matrix, rows, cols);
    colsum(matrix, rows, cols);

    return 0;
}

