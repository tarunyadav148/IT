#include<stdio.h>

//Fuction for getting largest element
void *find_largest(int a[],int n);

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

    int *largest = find_largest(arr,size);

    printf("Largest: %d",*largest);

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

void *find_largest(int a[],int n)
{
    int *largest = &a[0];
    for(int i=0;i<n;i++)
    {
        if(a[i]>*largest){
            largest = &a[i];
        }
    }
    return largest;
}