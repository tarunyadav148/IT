#include<stdio.h>

//Function for selection sort
void selection_sort(int arr[],int size);

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

    selection_sort(arr,size);

    printf("Element of array in sorted order: ");
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

void selection_sort(int arr[],int size)
{
    for(int i =0;i<size-1;i++)
    {
        int index_of_smallest = i;

        for(int j=i+1;j<size;j++)
        {
            //finding index of smallest element in range of i+1 to size
            if(arr[j]<arr[index_of_smallest])
                index_of_smallest = j;
        }

        //swap ith element with smallest element in range of i+1 to size
        int temp = arr[i];
        arr[i] = arr[index_of_smallest];
        arr[index_of_smallest] = temp;
    }
}

