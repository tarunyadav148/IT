#include<stdio.h>

//Function for taking element of array from user
void get_array(int arr[],int size);

//Function to display element of array
void show_array(int arr[],int size);

//Swap two integer
void swap(int *first,int *second)
{
    int temp = *second;
    *second = *first;
    *first = temp;
}

//Index of parent
int indexOfParent(int i)
{
    return (i-1)/2;
}

//Index of left chlid
int indexOfLeftChild(int i)
{
    return 2*i+1;
}

//Index of right chlid
int indexOfRightChild(int i)
{
    return 2*i+2;
}

//maxHeapify
void maxHeapify(int *arr, int size,int i)
{
    int l = indexOfLeftChild(i);
    int r = indexOfRightChild(i);
    int largest = i;
    if(l<size && arr[l]>arr[largest])
        largest = l;
    if(r<size && arr[r]>arr[largest])
        largest = r;
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        maxHeapify(arr,size,largest);
    }
}

//Build max Heap from array
void buildHeap(int *arr, int size)
{
    for(int i=size/2-1;i>=0;i--)
    {
        maxHeapify(arr,size,i);
    }
}

//Heap sort
void HeapSort(int *arr, int size)
{
    buildHeap(arr,size);
    for(int i = size-1;i>0;i--)
    {
        swap(&arr[0],&arr[i]);
        maxHeapify(arr,i,0);
    }
    
}

//Deletion in Heap
int delete(int *arr, int size)
{
    swap(&arr[0],&arr[size-1]);
    size--;
    maxHeapify(arr,size,0);
    return size;
}

//Insert in Heap
int insert(int *arr, int size, int num)
{
    int p , i = size;
    arr[size] = num;
    size++;
    while(i>0)
    {
        p = indexOfParent(i);
        if(arr[i]>arr[p])
        {
            swap(&arr[i],&arr[p]);
            i = p;
        }
        else
        {
            break;
        }
    }
    return size;
}

int main()
{
    int size;
    printf("Enter size of array:");
    scanf("%d",&size);

    int arr[size];

    printf("Enter array: ");
    get_array(arr,size);

    buildHeap(arr,size);

    printf("heap: ");
    show_array(arr,size);

    size = insert(arr,size,1000);

    printf("heap after delete: ");
    show_array(arr,size);

    

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