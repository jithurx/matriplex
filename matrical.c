// Author: Abhijith R
// github: https://github.com/jithurx
// Date: 26-Mar-2025
// MatriPlex (Matrix Calculation(or) Program) Ver-0.3-alpha
#include <stdio.h>
#define D 9 // Default dimension limit for the Matrices

int menu()
{
    int response;
    printf("1. Read\n2. Sum\n3. Multiply\n4. Transpose\n5. Display\n0. Exit\n");
    printf("Enter Option[0-5]: ");
    if (scanf("%d", &response) != 1 || response < 0 || response > 5) {
        printf("Invalid input! Please enter a number between 0 and 5.\n");
        return -1; // Invalid response
    }
    return response;
}

int choose_matrix(int r_flag)
{
    int choice;
    printf("Choose Matrix\n");
    printf("1. A\n2. B\n%s", r_flag ? "3. Result\n" : "");
    printf(">");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > (r_flag ? 3 : 2)) {
        printf("Invalid input! Please choose a valid matrix.\n");
        return -1; // Invalid choice
    }
    return choice;
}

void display(int row, int col, int matrix[D][D])
{
    printf("\nDisplay Matrix (%d x %d):\n", row, col);
    for (int i = 0; i < row; i++) {
        printf("|");
        for (int j = 0; j < col; j++) {
            printf(" %4d ", matrix[i][j]);
        }
        printf("|\n");
    }
}

void transpose(int row, int col, int matrix[D][D], int result[D][D])
{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    printf("Transpose completed.\n");
    display(row,col,result); // Display the transposed matrix
}

void sum(int row_a, int col_a, int mat_a[D][D], int row_b, int col_b, int mat_b[D][D], int result[D][D])
{
    if (row_a != row_b || col_a != col_b) {
        printf("Matrix addition is not defined for matrices of different dimensions!\n");
        return;
    }
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < col_a; j++) {
            result[i][j] = mat_a[i][j] + mat_b[i][j];
        }
    }
    printf("Matrix addition completed.\n");
    display(row_a, col_a, result); // Display the result
}

int definition_check(int col_a, int row_b)
{
    if (col_a != row_b) {
        printf("\nMatrix multiplication is not defined for these dimensions!\n");
        return 0;
    }
    return 1;
}

int matriplex(int row_a, int col_a, int mat_a[D][D], int row_b, int col_b, int mat_b[D][D], int result[D][D])
{
    if (!definition_check(col_a, row_b)) {
        return 0; // Multiplication not defined
    }
    for (int i = 0; i < row_a; i++) {
        for (int j = 0; j < col_b; j++) {
            result[i][j] = 0; // Initialize sum to zero
            for (int k = 0; k < col_a; k++) {
                result[i][j] += mat_a[i][k] * mat_b[k][j];
            }
        }
    }
    printf("Matrix multiplication completed.\n");
    display(row_a, col_b, result); // Display the result
    return 1;
}

void read_matrix(int matrix[D][D], int *r, int *c)
{
    int row, col;
    printf("Enter number of rows and columns for Matrix (row col): ");
    if (scanf("%d %d", &row, &col) != 2 || row <= 0 || col <= 0 || row > D || col > D) {
        printf("Invalid dimensions! Please enter valid dimensions within the limit (%d).\n", D);
        return;
    }
    *r = row;
    *c = col;
    printf("\nEnter elements for Matrix:\n");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Element (%d,%d): ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("Invalid input! Please enter integers only.\n");
                return;
            }
        }
    }
    display(row, col, matrix); // Debug
}
int main()
{
    int run_flag = 1, response, choice;
    // Matrix declaration
    int mat_a[D][D], mat_b[D][D], result[D][D];
    // Variable declarations for matrix dimensions
    int row_a = 0, col_a = 0, row_b = 0, col_b = 0;
    printf("--MATRIX CALCULATOR--\n");
    while (run_flag) {
        response = menu();
        if (response == -1) continue; // Invalid menu input
        switch (response) {
        case 1:
            choice = choose_matrix(0);
            if (choice == -1) break; // Invalid matrix choice
            switch (choice) {
            case 1:
                read_matrix(mat_a, &row_a, &col_a);
                break;
            case 2:
                read_matrix(mat_b, &row_b, &col_b);
                break;
            default:
                break;
            }
            break;
        case 2:
            sum(row_a, col_a, mat_a, row_b, col_b, mat_b, result);
            break;
        case 3:
            matriplex(row_a, col_a, mat_a, row_b, col_b, mat_b, result);
            break;
        case 4:
            choice = choose_matrix(1);
            if (choice == -1) break; // Invalid matrix choice
            switch (choice) {
            case 1:
                transpose(row_a, col_a, mat_a, result);
                break;
            case 2:
                transpose(row_b, col_b, mat_b, result);
                break;
            case 3:
                transpose(row_a, col_a, result, result);
                break;
            default:
                break;
            }
            break;
        case 5:
            choice = choose_matrix(1);
            if (choice == -1) break; // Invalid matrix choice
            switch (choice) {
            case 1:
                display(row_a, col_a, mat_a);
                break;
            case 2:
                display(row_b, col_b, mat_b);
                break;
            case 3:
                display(row_a, col_a, result);
                break;
            default:
                break;
            }
            break;
        case 0:
            run_flag = 0;
            break;
        default:
            printf("Invalid option! Please try again.\n");
            break;
        }
    }
    return 0;
}

