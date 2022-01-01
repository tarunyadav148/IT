#include<iostream>

using namespace std;

void SelectionSort(int arr[],int size)
{
    for(int i =0;i<size-1;i++)
    {
        int index_of_smallest = i;

        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[index_of_smallest])
                index_of_smallest = j;
        }
        int temp = arr[i];
        arr[i] = arr[index_of_smallest];
        arr[index_of_smallest] = temp;
    }
}


int main()
{
    int length;
    cout<<"Enter lenght of array:";
    cin>>length;

    int array[length];

    cout<<"Enter elements of array:";
    for(int i=0;i<length;i++)
        cin>>array[i];

    SelectionSort(array,length);
    cout<<"Sorted array:";
    for(int i=0;i<length;i++)
        cout<<array[i]<<" ";

    return 0;
}