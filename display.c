# include<stdio.h>

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
 int main()
 {
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int r=3,c=3;
    display(r,c,matrix);
    return 0;
 }