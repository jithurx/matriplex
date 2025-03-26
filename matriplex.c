// Author: Abhijith R
// github: https://github.com/jithurx
// Date: 26-Mar-2025
// MatriPlex (Matrix Multiplication Program) Ver-0.2-alpha
#include <stdio.h>

int matriplex(int row_a,int col_a,int mat_a[row_a][col_a],int row_b,int col_b,int mat_b[row_b][col_b],int result[row_a][col_b])
{
    // uncomment the following comment block to enable definition check within the function.
    /*if (col_a != row_b) 
    { // check if multiplication is defined
        printf("\nMatrix multiplication is not defined for these dimensions!\n");
        return 0;
    }*/
    for (int i = 0; i < row_a; i++) 
    { // Performs Matrix Multiplication
        for (int j = 0; j < col_b; j++) {
            result[i][j] = 0; // initialize sum to zero
            for (int k = 0; k < col_a; k++) {
                result[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }
    return 1;
}

int definition_check(int col_a,int row_b)
{
    if (col_a != row_b) 
    { // check if multiplication is defined
        printf("\nMatrix multiplication is not defined for these dimensions!\n");
        return 0;
    }
    return 1; 
}

void read_matrix(int row,int col,int matrix[row][col])
{
    printf("\nEnter elements for Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element (%d,%d): ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display(int row,int col,int matrix[row][col])
{
    printf("\nResult:\n");
    for (int i = 0; i < row; i++) {
        printf("|");
        for (int j = 0; j < col; j++) {
            printf(" %4d ", matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }
}
int main() {
    // variable declarations for matrix dimensions
    int row_a, col_a, row_b, col_b;
    
    // get matrix dimensions from user
    printf("Enter number of rows and columns for Matrix A (row col): ");
    scanf("%d %d", &row_a, &col_a);
    printf("Enter number of rows and columns for Matrix B (row col): ");
    scanf("%d %d", &row_b, &col_b);
    
    // definetion checking
    if(!definition_check(col_a,row_b)){return 0;} 
    
    // matrix declaration
    int mat_a[row_a][col_a], mat_b[row_b][col_b], result[row_a][col_b];
    
    // input matrix A
    read_matrix(row_a,col_a,mat_a);
    // input matrix B
    read_matrix(row_b,col_b,mat_b);

    // perform matrix multiplication - core code
    matriplex(row_a,col_a,mat_a,row_b,col_b,mat_b,result);
    
    // display resultant matrix
    display(row_a,col_b,result);
    
    // end of program
    return 0;
}

