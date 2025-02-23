// Author: Abhijith R
// github: https://github.com/jithurx
// MatriPlex (Matrix Multiplication Program) Ver-0.1-alpha
#include <stdio.h>

int main() {
    // variable declarations for matrix dimensions
    int row_a, col_a, row_b, col_b;
    
    // get matrix dimensions from user
    printf("Enter number of rows and columns for Matrix A (row col): ");
    scanf("%d %d", &row_a, &col_a);
    printf("Enter number of rows and columns for Matrix B (row col): ");
    scanf("%d %d", &row_b, &col_b);
    
    // check if multiplication is possible
    if (col_a != row_b) {
        printf("\nMatrix multiplication is not defined for these dimensions!\n");
        return 0;
    }
    
    // matrix declaration
    int mat_a[row_a][col_a], mat_b[row_b][col_b], result[row_a][col_b];
    
    // input matrix A
    printf("\nEnter elements for Matrix A:\n");
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < col_a; j++) {
            printf("Element (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat_a[i][j]);
        }
    }
    
    // input matrix B
    printf("\nEnter elements for Matrix B:\n");
    for (int i = 0; i < row_b; i++) {
        for (int j = 0; j < col_b; j++) {
            printf("Element (%d,%d): ", i + 1, j + 1);
            scanf("%d", &mat_b[i][j]);
        }
    }
    
    // perform matrix multiplication - core code block
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < col_b; j++) {
            result[i][j] = 0; // initialize sum to zero
            for (int k = 0; k < col_a; k++) {
                result[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }
    
    // display resultant matrix
    printf("\nResultant Matrix:\n");
    for (int i = 0; i < row_a; i++) {
        printf("|");
        for (int j = 0; j < col_b; j++) {
            printf(" %4d ", result[i][j]);
        }
        printf("|");
        printf("\n");
    }
    
    // end of program
    return 0;
}

