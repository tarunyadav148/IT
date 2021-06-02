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

typedef struct
{
    int row;
    int col;
    int value;
}Term;

typedef struct
{
    Term* term;
}SparseMatrix;

SparseMatrix* createSparseMatrix(int rows, int cols, int totalterms)
{
    SparseMatrix *sparsematrix = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    sparsematrix->term = (Term*)malloc((totalterms+1)*sizeof(Term));

    sparsematrix->term[0].row = rows;
    sparsematrix->term[0].col = cols;
    sparsematrix->term[0].value = totalterms;

    return sparsematrix;
}

SparseMatrix* getSparseMatrix(Matrix *matrx)
{
    int totalNonZeroTerm = 0;

    for(int i=0;i<matrx->rows;i++)
    {
        for(int j=0;j<matrx->cols;j++)
        {
            if(matrx->matrix[i][j]!=0)
                totalNonZeroTerm++;
        }
    }

    SparseMatrix *sparsematrix =  createSparseMatrix(matrx->rows,matrx->cols,totalNonZeroTerm);
    int termCounter = 1;

    for(int i=0;i<matrx->rows;i++)
    {
        for(int j=0;j<matrx->cols;j++)
        {
            if(matrx->matrix[i][j]!=0)
            {
                sparsematrix->term[termCounter].row = i;
                sparsematrix->term[termCounter].col = j;
                sparsematrix->term[termCounter].value = matrx->matrix[i][j];
                termCounter++;
            }
        }
    }
    return sparsematrix;
}

SparseMatrix* Transpose(SparseMatrix* sparsematrix)
{
    int rows = sparsematrix->term[0].row;
    int cols = sparsematrix->term[0].col;
    int totalterm = sparsematrix->term[0].value;

    SparseMatrix *transpose = createSparseMatrix(cols,rows,totalterm);

    int *rowTerms = (int*) calloc(cols,sizeof (int));
    int *stratingIndex = (int*) calloc(cols,sizeof (int));
    stratingIndex[0] = 1;

    for(int i=1;i<=totalterm;i++)
    {
        rowTerms[sparsematrix->term[i].col]++;
    }

    for(int i=1;i<cols;i++)
    {
        stratingIndex[i] = stratingIndex[i-1] + rowTerms[i-1];
    }

    int index;
    for(int i=1;i<=totalterm;i++)
    {
        index = stratingIndex[sparsematrix->term[i].col]++;

        transpose->term[index].row = sparsematrix->term[i].col;
        transpose->term[index].col = sparsematrix->term[i].row;
        transpose->term[index].value = sparsematrix->term[i].value;
    }

    return transpose;
}


void printSparseMatrix(SparseMatrix* sparsematrix)
{
    for(int i=0;i<sparsematrix->term[0].value+1;i++)
    {
        printf
                (
                        "%d %d %d \n",
                        sparsematrix->term[i].row,
                        sparsematrix->term[i].col,
                        sparsematrix->term[i].value
                );
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


    SparseMatrix *sparsematrix = getSparseMatrix(matrx);
    SparseMatrix *transpose = Transpose(sparsematrix);

    printf("Tanspose of sparse matrix:\n");
    printSparseMatrix(sparsematrix);
    printf("is:\n");
    printSparseMatrix(transpose);

    return 0;
}