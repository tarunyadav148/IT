#include<iostream>

using namespace std;

void InsertionSort(int array[],int size)
{
   int key;
   for (int j = 0; j < size; j++)
   {
       key = array[j];
       int i = j-1;   
       while (i>-1 && array[i]>key)
       {
           array[i+1] = array[i];
           i = i - 1;
       }
       array[i+1] = key;
   }
}

//Function for taking element of array from user
void getArray(int arr[],int size);

//Function to display element of array
void showArray(int arr[],int size);

int main()
{
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter array: ");
    getArray(arr,size);

    InsertionSort(arr,size);

    printf("sorted array: ");
    showArray(arr,size);
    
    return 0;
}

void getArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cin>>arr[i];
    }
}

void showArray(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
