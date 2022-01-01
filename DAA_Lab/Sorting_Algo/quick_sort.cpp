#include<iostream>

using namespace std;

void get_array(int arr[],int size);
void show_array(int arr[],int size);

void swap(int *first,int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}

int Partition(int *array,int startIndex,int endIndex)
{   
    int pivot = array[endIndex];
    int left = startIndex;
    int right = endIndex;

    int flag = 1;

    while (left!=right)
    {
        if(array[right]<pivot && flag)
        {
            array[left++] = array[right];
            flag = 0;
        }
        else if(array[right]>pivot && flag)
            right--;
        else if(array[left]>pivot)
        {
            array[right--] = array[left];
            flag = 1;
        }
        else
            left++;
    }

    array[left] = pivot;  //left == right

    return left;
    
}

void QuickSort(int *array,int startIndex,int endIndex)
{
    if(startIndex<endIndex)
    {
        int pivotIndex = Partition(array,startIndex,endIndex);
        QuickSort(array,startIndex,pivotIndex-1);
        QuickSort(array,pivotIndex+1,endIndex);
    }
}


int main()
{
    int n;
    printf("Enter size of array:");
    scanf("%d",&n);
    int arr[n];

    printf("Enter element of array:");
    get_array(arr,n);

    QuickSort(arr,0,n-1);

    printf("Sorted array:");
    show_array(arr,n);
    return 0;
}

void get_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
}

void show_array(int arr[],int size)
{
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}