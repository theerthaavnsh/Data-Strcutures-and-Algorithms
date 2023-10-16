#include <stdio.h>

int main() 
{
    int n;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);

    int adjacencyMatrix[n][n];
    
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < n; i++)
     {
        for (int j = 0; j < n; j++) 
        {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    //symmetry
    int isSymmetric = 1;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (adjacencyMatrix[i][j] != adjacencyMatrix[j][i]) 
            {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    if (isSymmetric)
     {
        printf("The adjacency matrix is symmetric.\n");
    } else 
    {
        printf("The adjacency matrix is not symmetric.\n");
    }

    // number of edges and degree of vertices
    int numEdges = 0;
    for (int i = 0; i < n; i++)
     {
        int degree = 0;
        for (int j = 0; j < n; j++) 
        {
            if (adjacencyMatrix[i][j] == 1) 
            {
                degree++;
                if (i == j) {
                    // avoid counting self-loops twice
                    degree--;
                }
                numEdges++;
            }
        }
        printf("Degree of vertex %d: %d\n", i + 1, degree);
    }

    //  calculate the number of edges (2 * number of edges)
    numEdges /= 2;
    printf("Number of edges: %d\n", numEdges);

    return 0;
}

