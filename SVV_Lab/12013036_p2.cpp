#include<iostream>

using namespace std;

int** create_matrix(int rows,int cols){
    int** matrix = (int**)malloc(sizeof(int*)*rows);

    for(int i=0;i<rows;i++){
            matrix[i] = (int*)malloc(sizeof(int)*cols);
    }
    
    return matrix;
}

void read_matrix(int** matrix,int rows,int cols){
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cin>>matrix[i][j];
        }
    }
}


void show_matrix(int** matrix,int rows,int cols){
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int** transpose(int** matrix,int rows,int cols,int* new_rows,int* new_cols){
    int** tanspose_matrix = create_matrix(cols,rows);
    *new_rows = cols;
    *new_cols = rows;

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            tanspose_matrix[j][i] = matrix[i][j];
        }
    }

    return tanspose_matrix;
}

int main(){
    int rows,cols;

    cout<<"Enter size of matrix (rows,cols): ";
    cin>>rows>>cols;

    int** matrix = create_matrix(rows,cols);

    cout<<"Enter matrix:"<<endl;
    read_matrix(matrix,rows,cols);
    cout<<"\n";

    cout<<"Matix:"<<endl;
    show_matrix(matrix,rows,cols);
    cout<<"\n";

    int *new_rows = (int*)malloc(sizeof(int));
    int *new_cols = (int*)malloc(sizeof(int));

    int** transpose_matrix = transpose(matrix,rows,cols,new_rows,new_cols);
    cout<<"Transpone matix:"<<endl;
    show_matrix(transpose_matrix,*new_rows,*new_cols);
    cout<<"\n";


    return 0;
}