#include <iostream>
#include <climits>

using namespace std;

int matrix_order(int a[], int n)
{
    int mini_mul[n][n];
    for (int i = 1; i < n; i++)
        mini_mul[i][i] = 0;

    for (int length = 2; length < n; length++)
    {
        for (int i = 1; i < n - length + 1; i++)
        {
            int j = i + length - 1;
            mini_mul[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++)
           {

            int q = mini_mul[i][k] + mini_mul[k + 1][j] + a[i - 1]* a[k]*a[j];
            if (q < mini_mul[i][j])
             mini_mul[i][j] = q;

           }
        }
    }

    return mini_mul[1][n - 1];
}

int main()
{
    int arr[] = {2, 3, 1, 4, 3};
    int size = 5;
    cout << "Minimum number of matrix multiplications: " << matrix_order(arr, size);
}
