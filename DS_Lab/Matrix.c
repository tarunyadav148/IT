#include<stdio.h>
#include<stdlib.h>

typedef struct 
{
    int **matrix;
    int rows;
    int cols;
}Matrix;


Matrix* createMatrix(int rows ,int cols)
{
    Matrix *matrx = (Matrix*)malloc(sizeof(Matrix));
    if(matrx==NULL)
        return NULL;
    matrx->matrix = (int**)malloc(sizeof(int*)*rows);
    if(matrx->matrix==NULL)
        return NULL;
    matrx->rows = rows;
    matrx->cols = cols;
    for(int i=0;i<rows;i++)
        matrx->matrix[i] = (int*)malloc(sizeof(int)*cols);
    return matrx;
}

void readMatrix(Matrix *matrx)
{
    for(int i=0;i<matrx->rows;i++)
    {
        for(int j=0;j<matrx->cols;j++)
        {
            scanf("%d",&matrx->matrix[i][j]);
        }
    }
}

void printMatrix(Matrix *matrx)
{
    for(int i=0;i<matrx->rows;i++)
    {
        for(int j=0;j<matrx->cols;j++)
        {
            printf("%d ",matrx->matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int rows,cols;
    printf("Enter number of rows and columns on matrix:");
    scanf("%d%d",&rows,&cols);

    Matrix* matrx = createMatrix(rows,cols);

    printf("Enter matrix:\n");
    readMatrix(matrx);

    printf("Matrix:\n");
    printMatrix(matrx);

    printf("Hello");
}