#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

// Function to multiply two matrices
int **matrixmultiply(int **mat1, int **mat2, int r1, int r2, int c2)
{
    int i, j, k;
    int **result = (int **)malloc(r1 * sizeof(int *));
    for (i = 0; i < r1; i++)
        result[i] = (int *)malloc(c2 * sizeof(int));
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < r2; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

// Function to create and input a matrix
int **create_and_input_matrix(int row, int col)
{
    int i, j;
    //time_t t;
    //srand((unsigned)time(&t));
    srand(time(0));
    int **mat = (int **)malloc(row * sizeof(int *));
    for (i = 0; i < row; i++)
        mat[i] = (int *)malloc(col * sizeof(int));
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            mat[i][j]=rand()%10;
        }
    }
    return mat;
}

void display_matrix(int **mat, int row, int col)
{
    int i, j;
    printf("Matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

// Function to calculate optimal parenthesization of matrix chain
void optimum_parenthesization_matrix_chain(int **mcount, int **split, int *matrix_dimension, int chain_size)
{
    int i, j, k, l, q;
    for (i = 1; i <= chain_size; i++)
        mcount[i][i] = 0;
    for (l = 2; l <= chain_size; l++) {
        for (i = 1; i <= chain_size - l + 1; i++) {
            j = i + l - 1;
            mcount[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++) {
                q = mcount[i][k] + mcount[k + 1][j] + matrix_dimension[i - 1] * matrix_dimension[k] * matrix_dimension[j];
                if (q < mcount[i][j]) {
                    mcount[i][j] = q;
                    split[i][j] = k;
                }
            }
        }
    }
}

void display_optimization_parenthesization(int **mcount, int **split,int i, int chain_size)
{
    if (i == chain_size) {
        printf(" A%d ", i);
    }
    else {
        printf("(");
        display_optimization_parenthesization(mcount, split, i, split[i][chain_size]);
        display_optimization_parenthesization(mcount, split, split[i][chain_size] + 1, chain_size);
        printf(")");
    }
}

// Function to multiply matrix chain optimally
int **multiply_matrixchain_optimally(int **mcount, int **split, int *matrix_dimension, int ***chain, int chain_size, int left, int right)
{
    if (left == right)
        return chain[left];
    else
    {
        int i;
        int **left_matrix = multiply_matrixchain_optimally(mcount, split, matrix_dimension, chain, chain_size, left, split[left][right]);
        int **right_matrix = multiply_matrixchain_optimally(mcount, split, matrix_dimension, chain, chain_size, split[left][right] + 1, right);

        int **result = (int **)malloc(matrix_dimension[left-1] * sizeof(int *));
        for (i = 0; i < matrix_dimension[left-1]; i++) {
            result[i] = (int *)malloc(matrix_dimension[right] * sizeof(int));
        }
        result=matrixmultiply(left_matrix, right_matrix, matrix_dimension[left-1], matrix_dimension[split[left][right]], matrix_dimension[right]);

        // It is unclear what you want to do with the resulting matrix
        // I am assuming that you want to store it in the chain array at the index left
        *chain = result;

        return result;
    }
}
int main() {
    int chain_size,*matrix_dimension,i;
    printf("Enter chain size:");
    scanf("%d",&chain_size);
    matrix_dimension=(int *)malloc(chain_size*sizeof(int));
    printf("Enter the dimensions of the matrices:");
    for(i=0;i<=chain_size;i++)
        scanf("%d",&matrix_dimension[i]);
    int **mcount = (int **)malloc((chain_size+1) * sizeof(int *));
    int **split = (int **)malloc((chain_size+1) * sizeof(int *));
    int ***chain = (int ***)malloc((chain_size+1) * sizeof(int **));
    int  j;
    for (i = 0; i <= chain_size; i++) {
        mcount[i] = (int *)malloc((chain_size+1) * sizeof(int));
        split[i] = (int *)malloc((chain_size+1) * sizeof(int));
        chain[i] = (int **)malloc((chain_size+1) * sizeof(int *));
    }
    for (i = 1; i <= chain_size; i++) {
        chain[i] = create_and_input_matrix(matrix_dimension[i-1], matrix_dimension[i]);
    }
    optimum_parenthesization_matrix_chain(mcount, split, matrix_dimension, chain_size);
    printf("Minimum number of multiplications: %d\n", mcount[1][chain_size]);
    printf("Optimal Parenthesization: ");
    display_optimization_parenthesization(mcount, split, 1, chain_size);
    printf("\n");
    int **result = multiply_matrixchain_optimally(mcount, split, matrix_dimension, chain, chain_size, 1, chain_size);
    printf("Resulting matrix:\n");
    display_matrix(result, matrix_dimension[0], matrix_dimension[chain_size]);
    return 0;
}