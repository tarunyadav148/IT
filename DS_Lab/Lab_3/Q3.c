#include<stdio.h>

//Function for linear search
int linear_search(int arr[],int size,int key);

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

    printf("Enter element of array: ");
    get_array(arr,size);

    int key;

    printf("Enter the element want to search in array: ");
    scanf("%d",&key);

    int index = linear_search(arr,size,key);

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

int linear_search(int arr[],int size,int key)
{
    int index = -1;

    for(int i=0;i<size;i++)
    {
        if(arr[i]==key)
        {
            index = i;
            break;
        }
    }

    return index;
}


