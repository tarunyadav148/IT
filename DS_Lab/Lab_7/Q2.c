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


SparseMatrix* Multiplication(SparseMatrix *m1,SparseMatrix *m2)
{
    if(m1->term[0].col!=m2->term[0].row)
    {
        printf("Multiplication not possible\n");
        exit(0);
    }
    
    SparseMatrix *tm2 = Transpose(m2);

    int rows1 = m1->term[0].row;
    int cols1 = m1->term[0].col;
    int totalterm1 = m1->term[0].value;
    int *rowTerms1 = (int*) calloc(rows1,sizeof (int));
    int *stratingIndex1 = (int*) calloc(rows1,sizeof (int));
    stratingIndex1[0] = 1;
    for(int i=1;i<=totalterm1;i++)
    {
        rowTerms1[m1->term[i].row]++;
    }
    for(int i=1;i<rows1;i++)
    {
        stratingIndex1[i] = stratingIndex1[i-1] + rowTerms1[i-1];
    }

    int rows2 = tm2->term[0].row;
    int cols2 = tm2->term[0].col;
    int totalterm2 = tm2->term[0].value;
    int *rowTerms2 = (int*) calloc(rows2,sizeof (int));
    int *stratingIndex2 = (int*) calloc(rows2,sizeof (int));
    stratingIndex2[0] = 1;
    for(int i=1;i<=totalterm2;i++)
    {
        rowTerms2[tm2->term[i].row]++;
    }
    for(int i=1;i<rows2;i++)
    {
        stratingIndex2[i] = stratingIndex2[i-1] + rowTerms2[i-1];
    }
    
    int nonzero1 =0 ,nonzero2 =0;
    for(int i=0;i<rows1;i++)
    {
        if(rowTerms1[i]!=0)
            nonzero1++;
    }
    for(int i=0;i<rows2;i++)
    {
        if(rowTerms2[i]!=0)
            nonzero2++;
    }
    SparseMatrix *mul = createSparseMatrix(rows1,rows2,nonzero1*nonzero2);
    int k =1;

    Term t;
    t.value = 0;

    for(int i=0;i<rows1;i++)
    {
        t.row = i;
        for(int j=0;j<rows2;j++)
        {
            t.col = j;
            for(int p=stratingIndex1[i];p<stratingIndex1[i]+rowTerms1[i];p++)
            {
                    for(int q=stratingIndex2[j];q<stratingIndex2[j]+rowTerms2[j];q++)
                    {
                        if(m1->term[p].col==tm2->term[q].col)
                        {
                            t.value += m1->term[p].value*tm2->term[q].value;
                        }
                    }
            }
            if(t.value!=0)
            {
                mul->term[k] = t;
                k++;
                t.value = 0;
            } 
        }

    }
    mul->term = realloc(mul->term,sizeof(Term)*(k));
    mul->term[0].value = k-1;
    return mul;
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
    int rows1,cols1,rows2,cols2;
    printf("Enter number of rows and columns on matrix 1:");
    scanf("%d%d",&rows1,&cols1);

    Matrix* matrx1 = createMatrix(rows1,cols1);

    printf("Enter matrix 1:\n");
    readMatrix(matrx1);

    printf("Enter number of rows and columns on matrix 2:");
    scanf("%d%d",&rows2,&cols2);

    Matrix* matrx2 = createMatrix(rows2,cols2);

    printf("Enter matrix 2:\n");
    readMatrix(matrx2);

    printf("\nSparseMatrix 1:\n");
    SparseMatrix* m1 = getSparseMatrix(matrx1);
    printSparseMatrix(m1);
    printf("SparseMatrix 2:\n");
    SparseMatrix* m2 = getSparseMatrix(matrx2);
    printSparseMatrix(m2);
    
    SparseMatrix *mul = Multiplication(m1,m2);
    printf("\nMultiplication of SparseMatrix 1 and SparseMatrix 2:\n");
    printSparseMatrix(mul);

    return 0;
}
