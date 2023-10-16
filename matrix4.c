#include <stdio.h>

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    
    int matrix[rows][cols];
    printf("Enter the matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    
    int saddle_points_found = 0;
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < cols; j++) 
        {
            int element = matrix[i][j];
            int is_saddle_point = 1; // Assume it's a saddle point

            //  smallest in the row
            for (int k = 0; k < cols; k++) 
            {
                if (matrix[i][k] < element) 
                {
                    is_saddle_point = 0;
                    break;
                }
            }

            // largest in the column
            for (int k = 0; k < rows; k++) 
            {
                if (matrix[k][j] > element) 
                {
                    is_saddle_point = 0;
                    break;
                }
            }

            // print saddle point 
            if (is_saddle_point) 
            {
                printf("Saddle point found at (%d, %d): %d\n", i, j, element);
                saddle_points_found = 1;
            }
        }
    }

    if (!saddle_points_found) {
        printf("No saddle points found in the matrix.\n");
    }

    return 0;
}

