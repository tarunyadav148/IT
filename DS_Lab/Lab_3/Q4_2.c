#include<stdio.h>

//Function for binary search
int binary_search(int arr[],int key,int low,int high);

//Function for taking element of array from user
void get_array(int arr[],int size);

//Function to display element of array
void show_array(int arr[],int size);

int main()
{
    int size;

    printf("Enter size of array: ");
    scanf("%d",&size);

    int arr[size];

    printf("Enter element of sorted array: ");
    get_array(arr,size);

    int key;

    printf("Enter the element want to search in array: ");
    scanf("%d",&key);

    int index = binary_search(arr,key,0,size-1);

    if(index != -1)
        printf("Element is at %d index",index);
    else
        printf("Element Not Found");

   
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

int binary_search(int arr[],int key,int low,int high)
{   
    if(low>high)
        return -1;
    
    int mid = (low+high)/2;

    if(arr[mid]==key)
        return mid;
    
    if(key>arr[mid])
        return binary_search(arr,key,mid+1,high);
    else
        return binary_search(arr,key,low,mid-1);
    
}


