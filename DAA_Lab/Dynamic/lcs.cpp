#include<iostream>

using namespace std;

int LCS(string A, string B)
{
    int len_A = A.length(), len_B = B.length();
    int table[len_A+1][len_B+1];
   
    for(int i=0;i<=len_A;i++)
    {
        for(int j=0;j<=len_B;j++)
        {
            if(i==0||j==0)
                table[i][j]=0;

            else if(A[i-1]==B[j-1])
                table[i][j]=table[i-1][j-1]+1;
            
            else
                table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
   
    return table[len_A][len_B];
}

int main(){
    string A = "thier";
    string B = "hi";
    cout<< LCS(A,B);
    return 0;
}