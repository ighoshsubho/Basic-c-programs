#include <stdio.h>
#include <stdlib.h>
#include <time.h>

FILE *fptr, *out_fptr;
int arr[3];

void adj_matrix(int n, int type)
{
    int **mat, i, j;
    mat = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
        mat[i] = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            mat[i][j] = 0;
    }
    if (type == 1)
    {
        while (!feof(fptr))
        {
            for (i = 0; i < 3; i++)
                fscanf(fptr, "%d", &arr[i]);
            mat[arr[0]][arr[1]] = arr[2];
        }
    }
    else
    {
        while (!feof(fptr))
        {
            for (i = 0; i < 3; i++)
                fscanf(fptr, "%d", &arr[i]);

            mat[arr[0]][arr[1]] = arr[2];
            mat[arr[1]][arr[0]] = arr[2];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d  ", mat[i][j]);
        printf("\n");
    }
}

int main()
{
    int n;
    fptr = fopen("./graphInput.txt", "r");
    fscanf(fptr, "%d", &n);
    adj_matrix(n, 0);
    printf("\n");
    fclose(fptr);
    return 0;
}