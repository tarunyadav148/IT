#include<iostream>

using namespace std;


class Matrix{
private:
    int rows;
    int cols;
    int** matrix;


public:
    Matrix(int rows,int cols){
        this->rows = rows;
        this->cols = cols;
        matrix = (int**)malloc(sizeof(int*)*rows);
        for(int i=0;i<rows;i++){
            matrix[i] = (int*)malloc(sizeof(int)*cols);
        }
    }

    int get_number_rows(){
        return rows;
    }

    int get_number_cols(){
        return cols;
    }

    void read(){
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cin>>matrix[i][j];
            }
        }
    }

    void show(){
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<matrix[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    static Matrix transpose(Matrix matrix){
        Matrix transpose_matrix(matrix.cols,matrix.rows);

        for(int i=0;i<matrix.rows;i++){
            for(int j=0;j<matrix.cols;j++){
                transpose_matrix.matrix[j][i] = matrix.matrix[i][j];
            }
        }

        return transpose_matrix;
    }

};



int main(){
    int rows,cols;

    cout<<"Enter size of matrix (rows,cols): ";
    cin>>rows>>cols;

    Matrix matrix(rows,cols);

    cout<<"Enter matrix:"<<endl;
    matrix.read();
    cout<<"\n";

    cout<<"Matix:"<<endl;
    matrix.show();
    cout<<"\n";

    Matrix transpose_matrix = Matrix::transpose(matrix);
    cout<<"Transpone matix:"<<endl;
    transpose_matrix.show();
    cout<<"\n";

    return 0;
}