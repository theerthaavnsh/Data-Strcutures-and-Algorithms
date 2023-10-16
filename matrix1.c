#include <stdio.h>

void Multiply(int m, int n, double A[][n], double v[], double result[]) 
{
    for (int i = 0; i < m; i++)
     {
        result[i] = 0;
        for (int j = 0; j < n; j++) 
        {
            result[i] += A[i][j] * v[j];
        }
    }
}

int main() 
{
    int m, n; // dimensions of the matrix A (m x n)
    
    printf("Enter the number of rows (m) for matrix A: ");
    scanf("%d", &m);
    printf("Enter the number of columns (n) for matrix A: ");
    scanf("%d", &n);
    
    double A[m][n];
    double v[n];
    double result[m];
    
    // input matrix A
    printf("Enter the elements of matrix A (%dx%d):\n", m, n);
    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++)
         {
            printf("A[%d][%d]: ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
    
    // input vector v
    printf("Enter the elements of vector v (%d elements):\n", n);
    for (int i = 0; i < n; i++) 
    {
        printf("v[%d]: ", i);
        scanf("%lf", &v[i]);
    }
    
    // compute A.v
    Multiply(m, n, A, v, result);
    
    // display the result
    printf("A.v = [");
    for (int i = 0; i < m; i++) 
    {
        printf("%.2f ", result[i]);
    }
    printf("]\n");
    
    return 0;
}

